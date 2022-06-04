use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;
struct Solution;

impl Solution {
    pub fn solution(s: String) -> i32 {
        let s = Rc::new(s);
        let map = Rc::new(RefCell::new(HashMap::new()));

        return Self::helper(0, s, map.clone());
    }
    pub fn helper(idx: usize, s: Rc<String>, map: Rc<RefCell<HashMap<usize, i32>>>) -> i32 {
        if let Some(v) = map.borrow().get(&idx) {
            return *v;
        }
        if idx == s.len() {
            return 1;
        }
        if let Some(s) = s.get(idx..idx + 1) {
            if s == "0" {
                return 0;
            }
        }
        if idx == s.len() - 1 {
            return 1;
        }
        let mut answer = Self::helper(idx + 1, s.clone(), map.clone());
        if let Some(ss) = s.get(idx..idx + 2) {
            if let Ok(n) = ss.parse::<i32>() {
                if n <= 26 {
                    answer += Self::helper(idx + 2, s.clone(), map.clone());
                }
            }
        }
        map.borrow_mut().insert(idx, answer);
        return answer;
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn answer() {
        let q = String::from("12");
        let answer = 2;
        assert_eq!(Solution::solution(q), answer);

        let q = String::from("226");
        let answer = 3;
        assert_eq!(Solution::solution(q), answer);

        let q = String::from("226");
        let answer = 3;
        assert_eq!(Solution::solution(q), answer);

        let q = String::from("0");
        let answer = 0;
        assert_eq!(Solution::solution(q), answer);

        let q = String::from("0");
        let answer = 0;
        assert_eq!(Solution::solution(q), answer);
    }
}
