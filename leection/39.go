package leection

func combinationSum(candidates []int, target int) [][]int {
	lens := len(candidates)
	var rul [][]int
	dp := make([]int, lens, lens)
	dp[0] = 0
	for i, n := range dp {
		dp[i] = lens + 1
		for val := range candidates {
			if i <= val {
				if dp[i] > dp[i-val]+1 {
					dp[i] = dp[i-val] + 1
				}
			}
		}
	}
}
