
function isLeaf(node){
	return (node === null) ? false : (node.right === null && node.left === null);
}

function deleteLeafFromTree(tree, node){
	if (tree === null || node === null) return 0;
	if (tree.left && tree.left.key === node.key){
		let l = tree.left;
		tree.left = null;
		return {deleted: l};
	} 
	if (tree.right && tree.right.key === node.key){
		let r = tree.right;
		tree.right = null;
		return {deleted: r};
	}
	else if (tree.key > node.key){
		deleteLeafFromTree(tree.left, node);
	} else {
		deleteLeafFromTree(tree.right, node);
	}
}

let res = [];
function deleteLeaf(node){
	if (node === null) return 0;
	if (isLeaf(node.left) && node.right === null){
		let p = deleteLeafFromTree(node, node.left);
		res.push(p);
	} else if (isLeaf(node.right) && node.left === null){
		let p = deleteLeafFromTree(node, node.right);
		res.push(p);
	}
	deleteLeaf(node.left);
	deleteLeaf(node.right);
}

function deleteLeafWithNoBrother(node, props){
	deleteLeaf(node);
	(props.shouldLog) ? console.log("deleted: ",res) : null;
}

module.exports = deleteLeafWithNoBrother;