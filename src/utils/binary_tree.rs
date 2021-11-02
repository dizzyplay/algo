use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

pub type Node = Option<Rc<RefCell<BinaryTreeNode>>>;
#[derive(Clone, Debug)]
pub struct BinaryTreeNode {
    pub val: i32,
    pub left: Node,
    pub right: Node,
}

impl BinaryTreeNode {
    pub fn new(val:i32) -> Self {
        BinaryTreeNode{
            val,
            left: None,
            right: None
        }
    }
}

#[derive(Debug)]
pub struct BinaryTree {
    root: Node,
}

impl BinaryTree {
    pub fn new(root_val: i32) -> Self {
        let n = BinaryTreeNode {
            val: root_val,
            left: None,
            right: None,
        };
        BinaryTree {
            root: Some(Rc::new(RefCell::new(n))),
        }
    }

    pub fn root<'a>(&self) -> Node {
        self.root.clone()
    }

    pub fn insert(&mut self, arr: Vec<Option<i32>>) {
        let mut target = VecDeque::from(arr);
        let mut queue: VecDeque<(Node, usize)> = VecDeque::new();
        if let Some(node) = self.root.as_ref() {
            queue.push_back((Some(node.clone()), 0));
        }
        while let Some(v) = target.pop_front() {
            match v {
                Some(v) => {
                    let node = Some(Rc::new(RefCell::new(BinaryTreeNode {
                        val: v,
                        left: None,
                        right: None,
                    })));
                    if let Some((first, f)) = queue.get_mut(0) {
                        if let Some(ff) = first.as_ref() {
                            if *f == 0 {
                                ff.borrow_mut().left = node.clone();
                                *f += 1;
                            } else if *f == 1 {
                                ff.borrow_mut().right = node.clone();
                                queue.pop_front();
                            }
                        }
                    }
                    queue.push_back((node.clone(), 0));
                }
                None => {
                    if let Some((_, f)) = queue.get_mut(0) {
                        if *f == 0 {
                            *f += 1;
                        } else if *f == 1 {
                            queue.pop_front();
                        }
                    }
                    queue.push_back((None, 0));
                }
            }
        }
    }
    pub fn bfs(&self) -> Vec<i32> {
        let mut queue = VecDeque::new();
        queue.push_back(self.root.clone());
        let mut result = Vec::new();
        while let Some(node) = queue.pop_front() {
            if let Some(n) = node.as_ref() {
                result.push(n.borrow().val);
                queue.push_back(n.borrow().left.clone());
                queue.push_back(n.borrow().right.clone());
            }
        }
        result
    }
    pub fn display(&self) {
        let mut queue = VecDeque::new();
        let mut result: Vec<Vec<String>> = Vec::new();

        queue.push_back((self.root.clone(), 0));
        while let Some((node, level)) = queue.pop_front() {
            if let Some(n) = node.as_ref() {
                queue.push_back((n.borrow().left.clone(), level + 1));
                queue.push_back((n.borrow().right.clone(), level + 1));
                if let Some(arr) = result.get_mut(level) {
                    arr.push(n.borrow().val.to_string());
                } else {
                    result.push(vec![n.borrow().val.to_string()]);
                }
            } else {
                if let Some(arr) = result.get_mut(level) {
                    arr.push(" ".to_string());
                } else {
                    result.push(vec![" ".to_string()]);
                }
                if level < 5 {
                    queue.push_back((None, level + 1));
                    queue.push_back((None, level + 1));
                }
            }
        }
        for row in result.iter() {
            println!("{:^30}", row.join("  "));
        }
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn binary_test() {
        use super::*;
        let mut tree = BinaryTree::new(1);
        tree.insert(Vec::from([None, Some(1), None, None, None, Some(1)]));
        assert_eq!(tree.bfs(), Vec::from([1, 1, 1]));
        let mut tree2 = BinaryTree::new(2);
        tree2.insert(Vec::from([Some(3), Some(0), None, None, None, Some(10)]));
        assert_eq!(tree2.bfs(), Vec::from([2, 3, 0, 10]));
        tree.display();
        tree2.display();
        let mut tree3 = BinaryTree::new(10);
        tree3.insert(Vec::from([
            Some(1),
            Some(2),
            Some(3),
            Some(4),
            Some(5),
            Some(6),
            Some(-10),
            Some(-1),
            Some(9),
        ]));
        tree3.display();
    }
}
