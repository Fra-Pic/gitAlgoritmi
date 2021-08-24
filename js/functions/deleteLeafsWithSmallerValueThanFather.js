
function isLeaf(node){
	return (node && node.left === null && node.right === null);
}

function deleteLeafsWithSmallerValueThanFather(root, deleted_arr){
	if (root === null) return 0;
	if (isLeaf(root.left) && root.key > root.left.key){
		deleted_arr.push(root.left);
		root.left = null;
	}
	if (isLeaf(root.right) && root.key > root.right.key){
		deleted_arr.push(root.right);
		root.right = null;
	}
	deleteLeafsWithSmallerValueThanFather(root.left, deleted_arr);
	deleteLeafsWithSmallerValueThanFather(root.right, deleted_arr);
	return root;
}

module.exports = deleteLeafsWithSmallerValueThanFather;