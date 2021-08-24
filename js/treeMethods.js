const recursiveHeight = require("./functions/recursiveHeight");
const log = require("./logger");

const loggerProps = {
	textColor: "blue",
	valueColor: "green"
};

class Node{
	
	constructor(key, left, right, props){
		this.key = key;
		this.left = left || null;
		this.right = right || null;
		if (props){
			this.level = props.level || null;
			this.color = props.color || null;
			this.parent = props.parent || null;
			this.type = props.type || null;
		}
		return this;
	}

	getLevel(){
		return this.level;
	}

	getValue(){
		return this.key;
	}

	setValue(key, left, right){
		this.key = key;
		this.left = left || null;
		this.right = right || null;
		return this;
	}
}

function printTreeLevels( u, type ){
	if (u === null || typeof u === "undefined") {
		return 0;
	} else {
		let parent = (u.parent) ? u.parent.key : "ROOT";
		switch (type){
			case "preorder": {
				log({key: u.key, msg: "\nlevel: "+u.level+ " \nParent Node: [" + parent +"]" + " \nType: ["+u.type+"]", loggerProps});
				printTreeLevels(u.left, type);
				printTreeLevels(u.right, type);
				break;
			}
			case "inorder": {
				printTreeLevels(u.left, type);
				log({key: u.key, msg: "\nlevel: "+u.level+ " \nParent Node: [" + parent +"]" + " \nType: ["+u.type+"]", loggerProps});
				printTreeLevels(u.right, type);
				break;
			}
			case "postorder": {
				printTreeLevels(u.left, type);
				printTreeLevels(u.right, type);
				log({key: u.key, msg: "\nlevel: "+u.level+ " \nParent Node: [" + parent +"]" + " \nType: ["+u.type+"]", loggerProps});
				break;
			}
			default: {
				printTreeLevels(u.left, type);
				log({key: u.key, msg: "\nlevel: "+u.level+ " \nParent Node: [" + parent +"]" + " \nType: ["+u.type+"]", loggerProps});
				printTreeLevels(u.right, type);
				break;
			}
		}
	}
}

function printTree(u, type){
	log({msg: "\n================\nTREE PRINTING START", textColor: "cyan"});
	printTreeLevels(u, type);
	log({msg: "TREE PRINTING END\n================\n", textColor: "cyan"});
}

function printLevelOrder(tree, tree_height){
	for (let i = 0; i < tree_height; i++){
		printByLevel(tree, 0, i);
	}
}

function printByLevel(node, level, sequential_index){
	if (node === null) {
		return;
	}
	if (level === sequential_index) {
		log({key:node.key, msg: "level: "+level+ " - sequential index: "+sequential_index, loggerProps});
	}
	if (level > sequential_index){
		return;
	} else {
		printByLevel(node.left, level+1, sequential_index);
		printByLevel(node.right, level+1, sequential_index);
	}
}

function randomColor(){
	let r = Math.floor(Math.random() * 75);
	if (r >= 0 && r <= 25){
		return "verde";
	} else if (r > 25 && r <= 50){
		return "rosso";
	} else {
		return "nero";
	}
}
function randomOperator(){
	let r = Math.floor(Math.random() * 75);
	if (r >= 0 && r <= 50){
		return "+";
	} else {
		return "*";
	}
}

function insertNode(root, val, props){
	if (root === null) {
		root = newNode(val, null, null, {color: randomColor(), level:props.level, parent: null});
		return root;
	} else {
		if (root.key > val){
			props.shouldLog ? log({left: true, key: val, msg: "root: "+root.key+" left: "+root.left?.key, loggerProps}) : null;
			if (root.left === null){
				root.left = newNode(val, null, null, {color: randomColor(), level:props.level, parent: root});
				return root.left;
			} else {
				insertNode(root.left, val, props);
			}
		} else {
			props.shouldLog ? log({right: true, key: val, msg: "root: "+root.key+" right: "+root.right?.key, loggerProps}) : null;
			if (root.right === null){
				root.right = newNode(val, null, null, {color: randomColor(), level:props.level, parent: root});
				return root.right;
			} else {
				insertNode(root.right, val, props);
			}
		}
	}
}

function newNode(key, left, right, props){
	return new Node(key, left, right, props);
}

function assignTypes(tree){
	if (tree === null) return;
	if(tree.left === null & tree.right === null) tree.type = "NUMBER";
	else tree.type = randomOperator();

	assignTypes(tree.left);
	assignTypes(tree.right);

}

function findHeight(node, val, height){
	if (node === null) return 0;
	else {
		if (val === node.key){
			return height;
		} else {
			let sx = findHeight(node.left, val, height + 1);
			let dx = findHeight(node.right, val, height + 1);
			//console.log(sx + " " + dx);
			return sx + dx;
		}
	}
}

function search(node, val){
	if (node === null) return null;
	if (node.key > val){
		return search(node.left, val);
	} else if (node.key < val){
		return search(node.right, val);
	} else {
		return node;
	}
}

function createTree( arr, props ){
	let root = newNode(arr[0], null, null, props);
	root.level = 0;
	if (arr.length > 1){
		for (let i = 1; i < arr.length; i++){
			props.shouldLog ?  log({key: arr[i], msg: "Inserting Node", loggerProps}) : null;
			insertNode(root, arr[i], props);
		}
		for (let i = 1; i < arr.length; i++){
			let node = search(root, arr[i]);
			let height = findHeight(root, node.key, 0);
			node.level = height;
			props.shouldLog ? 
				log({key: node.key, msg:"Inserted node at level: "+node.level, loggerProps}) : 
				null;
		}
		assignTypes(root);
	}
	
	return root;
}

module.exports = {Node, printTree, insertNode, newNode, createTree, printLevelOrder, search};