const chalk = require("chalk");
const {createTree, printTree, printLevelOrder, search} = require("./treeMethods");
const log = require("./logger");
const recursiveHeight = require("./functions/recursiveHeight");
const getNearestLeafToRoot = require("./functions/getNearestLeafToRoot");
const countTreeNodes = require("./functions/countTreeNodes");
const deleteLeafWithNoBrother = require("./functions/deleteLeafWithNoBrother");
const deleteLeafsWithSmallerValueThanFather = require("./functions/deleteLeafsWithSmallerValueThanFather");
const findKey = require("./functions/findStrictlyUpperValueKey");
const symbolSumTree = require("./functions/symbolSumTree");
const utils = require("./utils.js");


let deletionRoutine = (node) => {
	let deletedArr = [];
	deleteLeafsWithSmallerValueThanFather(node, deletedArr);

	log({msg: "Deleted leafs with values less than parent", header: true});
	for (let i = 0; i < deletedArr.length; i++){
		log({msg: "Deleted leaf with value: "+deletedArr[i].key, textColor: "blue"});
	}
	log({msg: "Deleted leafs with values less than parent", footer: true});

	let nodeCount2 = countTreeNodes(node);
	log({msg: "Tree nodes total count after deletion: "+nodeCount2, textColor: "blue"});
};

let symbolTreeRoutine = () => {
	let a1 = [20,25,15,12,17,22,27];
	let newTree1 = createTree(a1, {shouldLog: false});
	log({msg: "\nCreated new symbol tree", textColor: "cyan"});

	printTree(newTree1);
	let res = symbolSumTree(newTree1);
	log({msg: "Symbol sum tree result: "+res, textColor: "blue"});
};


function sumTreeValues(node){
	if (node === null) return 0;
	let left = sumTreeValues(node.left);
	let right = sumTreeValues(node.right);
	return (node.key + left + right);
}

function isLeaf(node){
	if (node === null) return false;
	return node.left === null && node.right === null;
}

function isBST(node, a, b){
	if (node === null) return true;
	else {
		return a < node.key && node.key < b && isBST(node.left,a,node.key) && isBST(node.right,node.key, b);
	}

}

function checkKeysInRange(node, lower_bound, upper_bound){
	if (node === null) return 0;
	else {
		if (node.key >= lower_bound && node.key <= upper_bound){
			return checkKeysInRange(node.left, lower_bound, upper_bound) + checkKeysInRange(node.right, lower_bound, upper_bound) + 1;
		} else {
			if (node.key < lower_bound){
				return checkKeysInRange(node.right, lower_bound, upper_bound);
			} else {
				return checkKeysInRange(node.left, lower_bound, upper_bound);
			}
		}
	}
}

function sumNodes(node){
	if (node === null) return 0;

	return node.key + sumNodes(node.left) + sumNodes(node.right);
}

function sumAtLevel(node, k){
	
	if (node === null){
		return 0;
	} else if (k === 0){
		return node.key;
	} else {
		return sumAtLevel(node.left, k - 1) + sumAtLevel(node.right, k-1);
	}
}

function isBalancedTree(node){
	if (node === null) return true;
	if (isLeaf(node.right) && isLeaf(node.left)) return true;
	else if (isLeaf(node.left) && node.right === null || isLeaf(node.right) && node.left === null) return false;
	return isBalancedTree(node.left) && isBalancedTree(node.right);
}

function max(a,b){
	return (a > b) ? a : b;
}

function maxIterInsideTree(node){
	if (node === null) return 0;
	return max(node.key + maxIterInsideTree(node.left), node.key + maxIterInsideTree(node.right));
}

function compareTrees(node1, node2){
	if (node1 === null || node2 === null) return true;
	if (node1.left && !node2.left || !node1.left && node2.left) return false;
	if ((node1.right && !node2.right) || (!node1.right && node2.right)) return false;
	return compareTrees(node1.left,node2.left) && compareTrees(node1.right, node2.right);
}

function lowestCommonAncestor(node, val1, val2){
	let cammino1 = [];
	let cammino2 = [];

	let node1 = search(node, val1);
	let node2 = search(node, val2);

	while(node1 !== null){
		cammino1.push(node1);
		node1 = node1.parent;
	}

	while(node2 !== null){
		cammino2.push(node2);
		node2 = node2.parent;
	}

	let newNode;
	while(cammino1.length > 0 && cammino2.length > 0 && cammino1[cammino1.length -1] === cammino2[cammino2.length -1]){
		newNode = cammino1[cammino1.length -1];
		cammino1.pop();
		cammino2.pop();
	}
	return newNode;
}

function sommaProfonditaK(node, curr, k){
	if (node === null) return 0;
	if (curr >= k){
		return node.key + sommaProfonditaK(node.left, curr+1, k) + sommaProfonditaK(node.right,curr+1,k);
	} else {
		return sommaProfonditaK(node.left, curr+1,k) + sommaProfonditaK(node.right, curr+1,k);
	}
}

function main(){
	let a = [10,9,8,4,12,19,15,17,25,22,27,24,16,3];
	let newTree = createTree(a, {shouldLog: false});
	
	let h = recursiveHeight(newTree, 0);
	log({msg: "Tree height: "+h, textColor: "blue"});

	let nearest = getNearestLeafToRoot(newTree, 0).node;
	log({msg: "Nearest leaf to root: "+nearest.key, textColor: "blue"});

	let nodeCount = countTreeNodes(newTree);
	log({msg: "Tree nodes total count: "+nodeCount, textColor: "blue"});

	let x = findKey(newTree, 19);
	log({msg: "Found key: "+x.key, textColor: "blue"});

	let sum = 0;
	let a1 = [20,25,15,12,17,22,27];
	let finalSum = 0;
	a1.forEach(a => finalSum += a);

	let newTree1 = createTree(a1, {shouldLog: false});
	let sumValue = sumTreeValues(newTree1);
	let isBstTree = isBST(newTree1, 1, 250) ? 1 : 0;
	let keys = checkKeysInRange(newTree, 10, 27);
	let nodeSum = sumNodes(newTree1);
	let sumLevel = sumAtLevel(newTree1, 1);
	let isBalanced = isBalancedTree(newTree1) ? 1 : 0;
	let maxIter = maxIterInsideTree(newTree1);

	let a2 = [30,35,25,22,27,32,37];
	let newTree2 = createTree(a1, {shouldLog: false});
	let confrontaAlberi = compareTrees(newTree1, newTree2) ? 1 : 0;

	let firstNode = 25;
	let secondNode = 15;
	let lca = lowestCommonAncestor(newTree1, firstNode, secondNode);

	let sommaLivelloK = sommaProfonditaK(newTree1, 0 , 2);
	log({msg:	"Tree Node sum: "+sumValue +
				"Expected sum: "+finalSum +
				"isBST: "+isBstTree+
				"Keys: "+keys+
				"Tree Node sum REMAKE:"+nodeSum+
				"Sum at level 2: "+sumLevel+
				"isBalanced: "+isBalanced+
				"maxIter: "+maxIter+
				"Compared Trees result:"+confrontaAlberi+
				"Lowest common ancestor: "+lca.key+
				"Somma a livello k: "+sommaLivelloK, textColor: "blue", valueColor: "yellow"});
	// symbolTreeRoutine();
	// deletionRoutine(newTree);
	// deleteLeafWithNoBrother(newTree, {shouldLog: true});


}

module.exports = main();