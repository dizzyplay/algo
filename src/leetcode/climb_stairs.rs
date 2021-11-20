struct Solution;

impl Solution {
    pub fn solution(n: i32) -> i32 {
        let mut first = 1;
        let mut second = 2;
        let mut answer = 0;
        for x in 0..n - 2 {
            answer = first + second;
            first = second;
            second = answer;
        }
        answer
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
}
