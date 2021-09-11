struct Solution;
use crate::utils::binary_tree::{BinaryTree, Node};
use std::collections::VecDeque;

impl Solution {
    fn is_uni(root: Node) -> bool {
        let mut queue = VecDeque::new();
        if let Some(n) = root.as_ref() {
            queue.push_back(n.clone());
        }
        let root_val = root.as_ref().unwrap().borrow().val;
        while let Some(n) = queue.pop_front() {
            if n.borrow().val != root_val {
                return false;
            }
            if let Some(left) = &n.borrow().left {
                queue.push_back(left.clone());
            }
            if let Some(right) = &n.borrow().right {
                queue.push_back(right.clone());
            }
        }
        true
    }
    fn solution(root: Node) -> i32 {
        let mut queue = VecDeque::new();
        queue.push_back(root.clone());
        let mut count = 0;
        while let Some(n) = queue.pop_front() {
            match n {
                Some(n) => {
                    if Self::is_uni(Some(n.clone())) {
                        count += 1;
                    }
                    if let Some(left) = &n.borrow().left {
                        queue.push_back(Some(left.clone()));
                    }
                    if let Some(right) = &n.borrow().right {
                        queue.push_back(Some(right.clone()));
                    }
                }
                None => {}
            }
        }
        count
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn answer() {
        let mut tree = BinaryTree::new(5);
        tree.insert(vec![Some(1), Some(5), None, Some(5), Some(5)]);
        assert_eq!(Solution::solution(tree.root()), 3);

        let mut tree2 = BinaryTree::new(5);
        tree2.insert(vec![
            Some(1),
            Some(1),
            Some(1),
            None,
            None,
            Some(2),
            Some(1),
            None,
            None,
            None,
            Some(1),
        ]);
        assert_eq!(Solution::solution(tree2.root()), 4);
    }
}
