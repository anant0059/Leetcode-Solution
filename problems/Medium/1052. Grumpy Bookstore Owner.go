func maxSatisfied(customers []int, grumpy []int, minutes int) int {
    res := 0
    n := len(customers)
    sm := 0
    sm_minutes := 0
    for i := 0; i < n; i++ {
        if grumpy[i] == 0 {
            sm += customers[i]
        } else if i < minutes {
            sm_minutes += customers[i]
        }
    }
    // fmt.Println(sm_minutes)
    for i := 0; i <= n - minutes; i++ {
        res = max(res, sm + sm_minutes)
        if i < n - minutes {
            if grumpy[i] == 1 {
                sm_minutes -= customers[i]
            }
            if grumpy[i+minutes] == 1 {
                sm_minutes += customers[i+minutes]
            }
            // fmt.Println(i, i+minutes, sm_minutes)
        }
    }
    return res
}