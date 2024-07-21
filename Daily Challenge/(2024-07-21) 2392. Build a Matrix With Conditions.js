/**
 * @param {number} k
 * @param {number[][]} rowConditions
 * @param {number[][]} colConditions
 * @return {number[][]}
 */
var buildMatrix = function(k, rowConditions, colConditions) {
    // Function to perform topological sorting using Kahn's algorithm
    const topoSort = (edges, n) => {
        // Create an adjacency list to store the edges
        const adj = Array.from({ length: n + 1 }, () => []);
        const deg = Array(n + 1).fill(0);
        const order = [];
        
        // Populate the adjacency list and in-degrees
        for (let [u, v] of edges) {
            adj[u].push(v);
            deg[v]++;
        }
        
        const q = [];
        // Push all integers with in-degree 0 in the queue
        for (let i = 1; i <= n; i++) {
            if (deg[i] === 0) q.push(i);
        }
        
        // Perform the topological sort
        while (q.length) {
            const f = q.shift();
            order.push(f);
            n--;
            for (let v of adj[f]) {
                if (--deg[v] === 0) q.push(v);
            }
        }
        
        // If we have not visited all integers, return empty array
        if (n !== 0) return [];
        return order;
    };

    // Get the topologically sorted sequences
    const orderRows = topoSort(rowConditions, k);
    const orderColumns = topoSort(colConditions, k);

    // If no topological sort exists, return empty array
    if (orderRows.length === 0 || orderColumns.length === 0) return [];

    const matrix = Array.from({ length: k }, () => Array(k).fill(0));
    const rowPosition = new Array(k + 1);
    const colPosition = new Array(k + 1);
    
    // Store positions of each number in the row and column orders
    for (let i = 0; i < k; i++) {
        rowPosition[orderRows[i]] = i;
        colPosition[orderColumns[i]] = i;
    }
    
    // Place numbers in the matrix according to their positions
    for (let i = 1; i <= k; i++) {
        matrix[rowPosition[i]][colPosition[i]] = i;
    }
    
    return matrix;
};
