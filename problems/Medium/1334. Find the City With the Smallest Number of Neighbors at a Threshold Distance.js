/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} distanceThreshold
 * @return {number}
 */
var findTheCity = function(n, edges, distanceThreshold) {
    let adj = Array.from({ length: n }, () => Array(n).fill(0));
    for(i of edges) {
        let from = i[0]
        let to = i[1]
        let weight = i[2]
        adj[from][to] = weight
        adj[to][from] = weight
    }
    console.log(adj)
    // let neighbours = Array(n).fill(0);
    let mn = n, index = n
    for(let i=0; i<n; i++) {
        let visited = Array(n).fill(-1);
        let queue = [i];
        visited[i] = 0;
        while(queue.length) {
            let first = queue.shift();
            for(let j=0; j<n; j++) {
                let tmp_weight = adj[first][j]
                if(tmp_weight != 0) {
                    if(visited[j] == -1 && visited[first] + tmp_weight <= distanceThreshold) {
                        visited[j] = visited[first] + tmp_weight
                        queue.push(j)
                    } else if(visited[j] > 0 && visited[first]  + tmp_weight < visited[j]) {
                        visited[j] = visited[first]  + tmp_weight
                        queue.push(j)
                    }
                }
            }
        }
        console.log(visited)
        let countVisited = visited.filter(value => value > 0 && value <= distanceThreshold).length;
        if(countVisited < mn) {
            mn = countVisited
            index = i
        } else if(countVisited == mn && index < i) {
            index = i
        }
        // neighbours[i] = countVisited
    }
    console.log(mn, index)
    return index
};