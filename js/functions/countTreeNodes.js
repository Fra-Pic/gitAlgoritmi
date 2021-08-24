function count(node){
	if (node === null){
		return 0;
	}else {
		let sumLeft = count(node.left);
		let sumRight = count(node.right);
		return sumLeft + sumRight + 1;
	}
}

function countTreeNodes(tree){
	let c = count(tree);
	return c;
}

module.exports = countTreeNodes;