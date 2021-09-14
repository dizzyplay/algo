struct Solution;
use crate::utils::binary_tree::{BinaryTree, Node};

impl Solution {
    fn is_uni(root: Node) -> (i32, bool) {
        match root.as_ref() {
            Some(n) => {
                match (&n.borrow().left, &n.borrow().right) {
                    (None, None) => {
                        return (1, true);
                    }
                    (Some(l), None) => {
                        let (t, f) = Self::is_uni(Some(l.clone()));
                        if l.borrow().val == n.borrow().val && f {
                            return (t + 1, true);
                        } else {
                            return (t, false);
                        }
                    }
                    (None, Some(r)) => {
                        let (t, f) = Self::is_uni(Some(r.clone()));
                        if r.borrow().val == n.borrow().val && f {
                            return (t + 1, true);
                        } else {
                            return (t, false);
                        }
                    }
                    (Some(l), Some(r)) => {
                        let (t1, f1) = Self::is_uni(Some(l.clone()));
                        let (t2, f2) = Self::is_uni(Some(r.clone()));
                        let f = f1 && f2;
                        if l.borrow().val == n.borrow().val && r.borrow().val == n.borrow().val && f
                        {
                            return (t1 + t2 + 1, true);
                        } else {
                            return (t1 + t2, false);
                        }
                    }
                };
            }
            None => return (0, false),
        };
    }
    fn solution(root: Node) -> i32 {
        Self::is_uni(root.clone()).0
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn answer0() {
        let mut tree = BinaryTree::new(1);
        tree.insert(vec![Some(1), None, Some(2)]);
        assert_eq!(Solution::solution(tree.root()), 1);
    }
    #[test]
    fn answer1() {
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
    #[test]
    fn answer2() {
        let mut tree = BinaryTree::new(1);
        tree.insert(vec![Some(2), Some(3), Some(4), Some(5)]);
        assert_eq!(Solution::solution(tree.root()), 3);

        let mut tree2 = BinaryTree::new(5);
        tree2.insert(vec![Some(5), Some(5), Some(5), Some(5), Some(5)]);
        assert_eq!(Solution::solution(tree2.root()), 6);
    }
}
