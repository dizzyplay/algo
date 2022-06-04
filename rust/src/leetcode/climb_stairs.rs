struct Solution;

impl Solution {
    pub fn solution(n: i32) -> i32 {
        let mut first = 1;
        let mut second = 2;
        let mut answer = 0;
        for _ in 0..n - 2 {
            answer = first + second;
            first = second;
            second = answer;
        }
        answer
    }
    pub fn solution2(n: i32) -> i32 {
        let mut dp = vec![0; n as usize];
        dp[0] = 1;
        dp[1] = 2;
        let n = n as usize;
        for i in 2..=n - 1 {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        dp[n - 1]
    }

    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        if cost.len() == 1 {
            return cost[0];
        }
        let mut answer = vec![0; cost.len() + 1];
        for i in 2..=cost.len() as usize {
            let one = answer[i - 2] + cost[i - 2];
            let two = answer[i - 1] + cost[i - 1];
            answer[i] = one.min(two);
        }
        answer[answer.len() - 1]
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn answer() {
        use super::*;
        assert_eq!(Solution::solution(3), 3);
        assert_eq!(Solution::solution(5), 8);

        assert_eq!(Solution::solution2(3), 3);
        assert_eq!(Solution::solution2(5), 8);
        assert_eq!(Solution::solution2(6), 13);

        assert_eq!(Solution::min_cost_climbing_stairs(vec![10, 15, 20]), 15);
    }
}
