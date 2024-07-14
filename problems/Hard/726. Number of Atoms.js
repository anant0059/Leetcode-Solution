/**
 * @param {string} formula
 * @return {string}
 */
var countOfAtoms = function (formula) {
    let stack = [];
    function isNumber(i) {
        return formula[i] >= 0 && formula[i] <= 9
    }

    function isSmall(i) {
        const char = formula[i]
        return char >= 'a' && char <= 'z'
    }

    function isCapital(i) {
        const char = formula[i]
        return char >= 'A' && char <= 'Z'
    }

    function parseNum(i) {
        let num = ''
        while (isNumber(i + 1)) {
            num += formula[i + 1];
            i++
        }

        return num ? Number(num) : 1;
    }

    let i = 0;

    while (i < formula.length) {
        if (isCapital(i)) {
            let name = formula[i];

            while (isSmall(i + 1)) {
                name += formula[i + 1];
                i++;
            }

            stack.push([name, parseNum(i)])
        } else if (formula[i] === '(') {
            stack.push(formula[i]);
        } else if (formula[i] === ')') {
            const newItems = []

            const num = parseNum(i);

            while (stack.at(-1) !== '(') {
                const [name, val] = stack.pop();
                newItems.push([name, val * num]);
            }

            stack.pop();

            while (newItems.length) {
                stack.push(newItems.pop())
            }
        }

        i++;
    }

    const map = {};

    for (const item of stack) {
        if (map[item[0]]) map[item[0]] += item[1];
        else map[item[0]] = item[1]
    }

    let str = '';

    Object.keys(map).sort().forEach((key) => {
        str += `${key}${map[key] > 1 ? map[key] : ''}`
    });

    return str
};