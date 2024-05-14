func f(grid [][]int, i int, j int) int {
    if i<0 || j<0 || i>=len(grid) || j>=len(grid[0]) || grid[i][j] == 0 {
        return 0
    }

    x := grid[i][j]
    grid[i][j] = 0
    ans := x+f(grid, i-1, j)
    ans = max(ans, x+f(grid, i+1, j))
    ans = max(ans, x+f(grid, i, j-1))
    ans = max(ans, x+f(grid, i, j+1))
    grid[i][j] = x

    return ans
}

func getMaximumGold(grid [][]int) int {
    ans := 0
    for i:=0; i<len(grid); i++ {
        for j:=0; j<len(grid[i]); j++ {
            ans = max(ans, f(grid, i, j))
        }
    }

    return ans
}


// type item struct {
//     i int
//     j int
//     sm int
// }

// func enqueue(queue[] item, element item) []item {
//   queue = append(queue, element); // Simply append to enqueue.
// //   fmt.Println("Enqueued:", element);
//   return queue
// }

// func dequeue(queue[] item) ([]item) {
//   if len(queue) == 0 {
//         // fmt.Println("Cannot dequeue from an empty queue")
//         return queue
//   }
// //   element := queue[0]; // The first element is the one to be dequeued.
// //   fmt.Println("Dequeued:", element)
//   return queue[1:]; // Slice off the element once it is dequeued.
// }

// func getMaximumGold(grid [][]int) int {
//     m := len(grid)
//     n := len(grid[0])

//     res := 0
//     for i:=0 ; i<m ; i++ {
//         for j:=0 ; j<n ; j++ {
//             if grid[i][j] != 0 {
//                 tmp := find_max_gold(i, j, grid, m, n)
//                 res = max(res, tmp)
//                 fmt.Println(i, j, tmp)
//             }
//         }
//     }
//     return res
// }

// func find_max_gold(i int, j int, grid [][]int, m int, n int) int {
//     var queue []item
//     mx := grid[i][j]
//     // visited := grid
//     visited := make([][]int, m)
//     for i := range visited {
//         visited[i] = make([]int, n)
//         copy(visited[i], grid[i])
//     }
//     // fmt.Println(visited)
//     visited[i][j] = 0

//     queue = enqueue(queue, item{i, j, mx})
//     for len(queue) > 0 {
//         // fmt.Println("Hi")
//         tmp_item := queue[0]
//         queue = dequeue(queue)
//         i := tmp_item.i
//         j := tmp_item.j
//         sm := tmp_item.sm
//         mx = max(mx, sm)
//         if i > 0 && i < m && j >= 0 && j < n && visited[i-1][j] != 0{
//             queue = enqueue(queue, item{i-1, j, sm + visited[i-1][j]})
//             visited[i-1][j] = 0
//         }
//         if i >= 0 && i < m-1 && j >= 0 && j < n && visited[i+1][j] != 0{
//             queue = enqueue(queue, item{i+1, j, sm + visited[i+1][j]})
//             visited[i+1][j] = 0
//         }
//         if i >= 0 && i < m && j > 0 && j < n && visited[i][j-1] != 0{
//             queue = enqueue(queue, item{i, j-1, sm + visited[i][j-1]})
//             visited[i][j-1] = 0
//         }
//         if i >= 0 && i < m && j >= 0 && j < n-1 && visited[i][j+1] != 0{
//             queue = enqueue(queue, item{i-1, j, sm + visited[i][j+1]})
//             visited[i][j+1] = 0
//         }
//     }

//     return mx
// }