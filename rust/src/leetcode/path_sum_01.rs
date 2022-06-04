struct Solution;
use crate::utils::binary_tree::{BinaryTree, Node};

impl Solution {
    pub fn solution(root: Node, target_sum: i32) -> bool {
        Self::has_path_sum(root, target_sum)
    }
    pub fn has_path_sum(root: Node, mut target_sum: i32) -> bool {
        if root.is_none() {
            return false;
        }
        target_sum -= root.as_ref().unwrap().borrow().val;
        let left = root.as_ref().unwrap().borrow().left.clone();
        let right = root.as_ref().unwrap().borrow().right.clone();
        match (left, right) {
            (None, None) => target_sum == 0,
            (Some(x), None) | (None, Some(x)) => Self::has_path_sum(Some(x), target_sum),
            (Some(r), Some(l)) => {
                Self::has_path_sum(Some(l), target_sum) || Self::has_path_sum(Some(r), target_sum)
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn answer() {
        let mut tree = BinaryTree::new(-1);
        tree.insert(vec![Some(-1), Some(-2)]);
        assert_eq!(Solution::solution(tree.root(), -3), true);
    }
}
