use crate::utils::binary_tree::{BinaryTree, Node};
struct Solution;

impl Solution {
    pub fn solution(root: Node, target: i32) -> bool {
        if let Some(node) = root {
            let s = target - node.borrow().val;
            if s == 0 && node.borrow().left.is_none() && node.borrow().right.is_none() {
                return true;
            } else if s < 0 {
                return false;
            }
            return Self::solution(node.borrow().left.clone(), s)
                || Self::solution(node.borrow().right.clone(), s);
        }
        false
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn answer() {
        use super::*;

        let mut tree = BinaryTree::new(10);
        tree.insert(vec![Some(2), Some(3), Some(3), Some(10)]);
        tree.display();
        assert_eq!(Solution::solution(tree.root(), 12), false);
        assert_eq!(Solution::solution(tree.root(), 15), true);
        assert_eq!(Solution::solution(tree.root(), 1), false);
        assert_eq!(Solution::solution(tree.root(), 1), false);
        println!("{:?}", Solution::solution(tree.root(), 13));
    }
}
