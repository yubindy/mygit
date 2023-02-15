package leection

import "testing"

func wordBreak(s string, wordDict []string) bool {
	t := make(map[string]bool)
	for _, w := range wordDict {
		t[w] = true
	}
	dp := make([]bool, len(s)+1)
	dp[0] = true
	for i, _ := range s {
		for j := 0; j < i; j++ {
			if dp[j] && t[s[j:i-j]] {
				dp[j] = true
				break
			}
		}
	}
	return dp[len(s)]
}

func Test139(t *testing.T) {
	tt := make(map[string][]string)
	tt["leetcode"] = []string{"leet", "code"}
	for k, v := range tt {
		println(wordBreak(k, v))
	}
}
