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
        let mut dp = vec![0; (n - 1) as usize];
        dp[0] = 1;
        dp[1] = 2;
        let n = n as usize;
        for i in 2..=n - 1 {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        dp[n - 1]
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn answer() {
        use super::*;
        assert_eq!(Solution::solution(3), 3);
        assert_eq!(Solution::solution(5), 8);
    }
    #[test]
    fn answer2() {
        use super::*;
        assert_eq!(Solution::solution2(3), 3);
        assert_eq!(Solution::solution2(5), 8);
        assert_eq!(Solution::solution2(6), 13);
    }
}
