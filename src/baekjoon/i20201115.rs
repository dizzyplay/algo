struct Solution {}

impl Solution {
    fn sol(arr: Vec<u32>, mut k: u32) -> u32 {
        let mut result = Vec::new();
        let mut limit = arr.len();
        let mut point = arr.len();
        while k != 0 {
            let mut max = 0;
            for i in (k - 1) as usize..limit {
                if arr[i] >= max {
                    max = arr[i];
                    point = i;
                }
            }
            limit = point;
            result.push(max - (k - 1));
            k -= 1;
        }
        result.iter().sum()
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn answer() {
        use super::*;
        let v = vec![2, 3, 1, 2, 1];
        let k = 3;
        assert_eq!(Solution::sol(v, k), 4);
        let v = vec![4, 3, 2, 8, 3];
        let k = 3;
        assert_eq!(Solution::sol(v, k), 12);
    }
}
