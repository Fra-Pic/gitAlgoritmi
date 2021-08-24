function max(a, b){
	return (a > b) ? a : b;
}

function recursiveH(node, level){
	if (node === null){
		return level;
	} else {
		return max(recursiveH(node.left, level+1), recursiveH(node.right, level+1));
	}
}

function recursiveHeight(node, level){
	let h = recursiveH(node, level);
	return h;
}

module.exports = recursiveHeight;