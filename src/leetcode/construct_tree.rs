use std::borrow::Borrow;
use crate::utils::binary_tree::{BinaryTree, BinaryTreeNode};
use std::collections::HashMap;
use std::rc::Rc;
use std::cell::RefCell;

struct Solution;

impl Solution {
    pub fn solution(inorder:Vec<i32>, postorder:Vec<i32>) {
        let mut p = Rc::new(RefCell::new(postorder));
        let mut m = HashMap::new();
        inorder.iter().enumerate().for_each(|(idx,v)| {
            m.insert(idx as i32,v);
        });
        let m = Rc::new(m);
        println!("{:?}",m);
        fn helper(in_left:usize, in_right:usize, pc: Rc<RefCell<Vec<i32>>>, mm: Rc<HashMap<i32,&i32>>) -> Option<BinaryTreeNode> {
            if in_left > in_right {
                return None;
            }
            let val = pc.clone().borrow_mut().pop().unwrap();
            let index = mm.get(&val).unwrap();
            let mut root = BinaryTree::new(val).root();
            println!("{}", index);
            root.unwrap().borrow_mut().right = Some(Rc::new(RefCell::new(BinaryTreeNode::new(1))));
            Some(BinaryTreeNode::new(1))
        }
        helper(0, inorder.len() - 1, p.clone(), m.clone());
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn answer(){
        use super::*;
        let s = Solution::solution([3,2,1].to_vec(),[3,1,2].to_vec());
        println!("{:?}", s);
    }
}
