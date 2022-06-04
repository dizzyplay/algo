use crate::utils::binary_tree::{BinaryTree, Node};
use std::collections::VecDeque;
use std::iter;

fn inorder_traversal(root: Node) -> Vec<i32> {
    if let Some(node) = root {
        return inorder_traversal(node.borrow().left.clone())
            .into_iter()
            .chain(iter::once(node.borrow().val))
            .chain(inorder_traversal(node.borrow().right.clone()))
            .collect::<Vec<i32>>();
    }
    vec![]
}

fn preorder_traversal(root: Node) -> Vec<i32> {
    if let Some(node) = root {
        return iter::once(node.borrow().val)
            .chain(preorder_traversal(node.borrow().left.clone()))
            .chain(preorder_traversal(node.borrow().right.clone()))
            .collect::<Vec<i32>>();
    }
    vec![]
}

fn postorder_traversal(root: Node) -> Vec<i32> {
    if let Some(node) = root {
        return postorder_traversal(node.borrow().left.clone())
            .into_iter()
            .chain(postorder_traversal(node.borrow().right.clone()))
            .chain(iter::once(node.borrow().val))
            .collect::<Vec<i32>>();
    }
    vec![]
}

fn bfs(root: Node) -> Vec<i32> {
    let mut result = vec![];
    let mut queue = VecDeque::new();
    match root {
        Some(n) => queue.push_back(n.clone()),
        None => return vec![],
    }
    while let Some(node) = queue.pop_front() {
        result.push(node.borrow().val);
        if let Some(left) = node.borrow().left.clone() {
            queue.push_back(left.clone());
        }
        if let Some(right) = node.borrow().right.clone() {
            queue.push_back(right.clone());
        }
    }
    result
}

#[cfg(test)]
mod tests {
    #[test]
    fn inorder_test() {
        use super::*;
        let mut tree = BinaryTree::new(1);
        tree.insert(vec![Some(2), Some(3), Some(4), Some(5), Some(6), Some(7)]);
        // 1
        // 2 3
        // 45 67
        tree.display();
        assert_eq!(inorder_traversal(tree.root()), vec![4, 2, 5, 1, 6, 3, 7])
    }
    #[test]
    fn preorder_test() {
        use super::*;
        let mut tree = BinaryTree::new(1);
        tree.insert(vec![Some(2), Some(3), Some(4), Some(5), Some(6), Some(7)]);
        assert_eq!(preorder_traversal(tree.root()), vec![1, 2, 4, 5, 3, 6, 7]);
    }
    #[test]
    fn post_test() {
        use super::*;
        let mut tree = BinaryTree::new(1);
        tree.insert(vec![Some(2), Some(3), Some(4), Some(5), Some(6), Some(7)]);
        assert_eq!(postorder_traversal(tree.root()), vec![4, 5, 2, 6, 7, 3, 1]);
    }
    #[test]
    fn bfs() {
        use super::*;
        let mut tree = BinaryTree::new(1);
        tree.insert(vec![Some(2), Some(3), Some(4), Some(5), Some(6), Some(7)]);
        assert_eq!(bfs(tree.root()), vec![1, 2, 3, 4, 5, 6, 7]);

        let mut tree = BinaryTree::new(3);
        tree.insert(vec![Some(3), Some(3), Some(4), Some(5), Some(6), Some(7)]);
        assert_eq!(bfs(tree.root()), vec![3, 3, 3, 4, 5, 6, 7]);
    }
}
