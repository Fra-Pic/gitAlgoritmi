function minBST(root){
	while( root.left !== null){
		root = root.left;
	}
	return root;
}

function successorBST(root){
	if (root === null) return 0;
	if (root.right !== null){
		return minBST(root.right);
	}
	let parent = root.parent;
	while(parent !== null && root === parent.right){
		root = parent;
		parent = parent.parent;
	}
	return parent;
}

function findKey(root, val){
	if (root === null) return;
	if (root.key === val){
		return successorBST(root);
	} else {
		let sx = findKey(root.left, val);
		let dx = findKey(root.right, val);
		return sx || dx;
	}
}

module.exports = findKey;