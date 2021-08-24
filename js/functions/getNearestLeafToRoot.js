function min(a, b){
	return (a.level < b.level) ? a : b;
}

function getNearestLeaf(node, level){

	if (node === null) {
		return {node, level:10000};
	}

	if (node.left === null && node.right === null){
		return {node, level: level + 1};
	}

	let leftLevel = getNearestLeaf(node.left, level+1);
	let rightLevel = getNearestLeaf(node.right, level+1);

	return min(leftLevel, rightLevel);
	
}

function getNearestLeafToRoot(node, level){
	let nearest = getNearestLeaf(node, level);
	return nearest;
}

module.exports = getNearestLeafToRoot;