use std::collections::VecDeque;

struct Solution {}

impl Solution {
    pub fn find(val: usize) -> String {
        let mut queue = VecDeque::new();
        let mut visited = vec![];
        queue.push_back((1, String::from("1")));
        while let Some(node) = queue.pop_front() {
            let (n, s) = (node.0, node.1);
            if s.len() > 100 {
                break;
            }
            let rest = n % val;
            if rest == 0 {
                return s;
            }
            if visited.contains(&rest) {
                continue;
            }
            visited.push(rest);
            let mut s1 = s.clone();
            s1.push_str("0");
            let mut s2 = s.clone();
            s2.push_str("1");
            queue.push_back(((rest * 10), s1));
            queue.push_back(((rest * 10) + 1, s2));
        }
        String::from("no")
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn answer01() {
        use super::*;
        //assert_eq!(Solution::find(17), String::from("11101"));
        //assert_eq!(Solution::find(11011), String::from("11011"));
        //assert_eq!(
        //    Solution::find(999),
        //    String::from("111111111111111111111111111")
        //);
        //assert_eq!(Solution::find(125), String::from("1000"));
        //assert_eq!(Solution::find(173), String::from("1011001101"));
        assert_eq!(Solution::find(17), String::from("11101"));
        use std::time::Instant;
        let now = Instant::now();
        for i in 1..100 {
            Solution::find(i);
        }
        let new_now = Instant::now();
        println!("{:?}", new_now.duration_since(now));
    }
}
