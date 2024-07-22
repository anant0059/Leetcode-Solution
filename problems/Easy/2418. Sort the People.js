/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
var sortPeople = function(names, heights) {
    return names.map((name, i) => {
                 // Create an object with the name and corresponding height
                 return { name: name, height: heights[i] };
                })
                .sort((a, b) => {
                 // Sort the array of objects by height in descending order
                 return b.height - a.height;
                })
                .map(obj => {
                 // Extract the name from each sorted object
                 return obj.name;
                });
};