function symbolSumTree(node){
	if (node === null) return null;
	if (node.type === "NUMBER") return node.key;
	if (node.type === "+") return symbolSumTree(node.left) + symbolSumTree(node.right);
	if (node.type === "*") return symbolSumTree(node.left) * symbolSumTree(node.right);
}

module.exports = symbolSumTree;