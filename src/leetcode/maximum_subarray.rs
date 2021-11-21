struct Solution;

impl Solution {
    pub fn solution(arr: Vec<i32>) -> i32 {

        let mut current = arr[0];
        let mut max = arr[0];

        for i in 1..arr.len() as usize {
            current = arr[i].max(current + arr[i]);
            max = max.max(current);
        }
        max
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn answer() {
        use super::*;

        assert_eq!(Solution::solution(Vec::from([-2,1,-3,4,-1,2,1,-5,4])), 6);
        assert_eq!(Solution::solution(Vec::from([1,2,-3,5])), 5);
    }
}
