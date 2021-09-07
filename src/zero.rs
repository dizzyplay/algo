struct Solution {}
use std::collections::VecDeque;

impl Solution {
    pub fn find(val: usize) -> String {
        let mut queue = VecDeque::new();
        let mut visited = vec![];

        queue.push_back((1, String::from("1")));
        while let Some(node) = queue.pop_front() {
            // println!("{}", node.1);
            if node.1.len() > 30 {
                return String::from("no");
            }
            if node.0 % val == 0 {
                return node.1;
            } else if visited.contains(&(node.0 % val)) {
                continue;
            }
            visited.push(node.0 % val);
            let mut s = node.1.clone();
            s.push_str("0");
            let mut s1 = node.1.clone();
            s1.push_str("1");
            queue.push_back(((node.0 % val) * 10, s));
            queue.push_back(((node.0 % val) * 10 + 1, s1));
        }
        String::new()
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn check() {
        use crate::zero;
        use std::time::Instant;
        let now = Instant::now();
        assert_eq!(zero::Solution::find(17), String::from("11101"));
        println!("hellp");
        println!("{}", now.elapsed().as_millis());
        //assert_eq!(zero::Solution::find(11011), String::from("11011"));
        //assert_eq!(zero::Solution::find(17), String::from("11101"));
        //assert_eq!(
        //    zero::Solution::find(999),
        //    String::from("111111111111111111111111111")
        //);
        //assert_eq!(zero::Solution::find(125), String::from("1000"));
        //assert_eq!(zero::Solution::find(173), String::from("1011001101"));
        //for i in 1..50 {
        //    let answer = zero::Solution::find(i);
        //    println!("{:>5} {:>30}", i, answer);
        //    if answer == String::from("no") {
        //        println!("{}", i);
        //    }
        //}
    }
}
