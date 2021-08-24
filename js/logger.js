/*===============================================================================================*/
const chalk = require("chalk");

String.prototype.padding = function(n, c)
{
	var val = this.valueOf();
	if ( Math.abs(n) <= val.length ) {
		return val;
	}
	var m = Math.max((Math.abs(n) - this.length) || 0, 0);
	var pad = Array(m + 1).join(String(c || " ").charAt(0));
	return (n < 0) ? pad + val : val + pad;
};

/**
 * Print utils for binary trees,
 * 
 * msg field does NOT accept strings formatted diffrently from <phrase>:<value> <phrase>:<value> and so on
 * 
 * @param {Object} nodeObj printObject
 * - header
 * - footer
 * - textColor
 * - valueColor
 * - right
 * - left
 * - msg
 * - key
 */

function treeLogFormatter(nodeObj){
	let textColor = "black";
	let valueColor = "green";

	if (nodeObj.header){
		return chalk.bgGray("============") + " [HEADER] " + nodeObj.msg.toString().padding(45) + chalk.bgGray("============");
	}
	if (nodeObj.footer){
		return chalk.bgGray("============") + " [FOOTER] "+ nodeObj.msg.toString().padding(45) + chalk.bgGray("============");
	}
	if (nodeObj.textColor){
		textColor = nodeObj.textColor;
	}
	if (nodeObj.valueColor){
		valueColor = nodeObj.valueColor;
	}
	
	if (nodeObj.right){
		let msg = (nodeObj.msg) ? nodeObj.msg : " ".padding(2);
		return chalk.black.bgGreen("["+"RIGHT".padding(5)+"]")+ chalk.green(" ["+nodeObj.key+"] - ") + msg.padding(3);
	} else if(nodeObj.left){
		let msg = (nodeObj.msg) ? nodeObj.msg : " ";
		return chalk.black.bgCyan("["+"LEFT".padding(5)+"]") + chalk.cyan(" ["+nodeObj.key+"] - ") + msg;
	} else{
		let msg = (nodeObj.msg)
			? nodeObj.key 
				? " - " + nodeObj.msg 
				: nodeObj.msg
			: "";
		let key = (nodeObj.key) ? chalk.black.bgCyan("["+nodeObj.key.toString().padding(5)+"]") : "";
		if (key.length < 1){
			if (msg.length > 1){
				let m = msg.split(":");
				let newStr = "";
				if (m.length === 2){
					for (let i = 0; i < m.length; i++){
						if (i % 2 === 0 | i === 0){
							newStr += chalk[textColor](m[i]+":");
						} else {
							newStr += chalk[valueColor].bold(m[i]);
						}
					}
				} else if (m.length < 2){
					newStr += chalk[textColor].bold(msg);
				} else if (m.length > 2){
					newStr += chalk[textColor].bold("---- [START] multiple msg parameters ----\n");
					for (let i = 0; i < m.length - 1; i++){
						let parseIntRegEx = /^\s*\,?[0-9]*/;
						let numberBeforeStringRegEx = /^\s*?[0-9]*\d[a-zA-Z0-9\s]*$/;
						let checkNumberInStringRegEx = /\d+/;
						let checkNumberOrNumberArrayInStringRegEx = /\-?\d+(?:\,?\-?\d*)+/;
						let checkStringArrayRegEx = /\'?[a-zA-Z]+\'?(?:\,\s?\'?[a-zA-Z]*\'?)+/;
						let checkTextInStringRegEx = /[a-zA-Z\s]+/;


						let textPart = m[i + 1].split(checkNumberInStringRegEx)[1]?.trim() || "";
						let numberPart;
						if (m[i + 1].match(checkNumberOrNumberArrayInStringRegEx)){
							numberPart =  m[i + 1].match(checkNumberOrNumberArrayInStringRegEx)[0].trim();
						} 
						if (m[i + 1].match(checkStringArrayRegEx)){
							numberPart = m[i + 1].match(checkStringArrayRegEx)[0];
						}
						

						textPart = textPart.match(checkTextInStringRegEx) ? textPart.match(checkTextInStringRegEx)[0].trim() : textPart;
						nodeObj.msg = textPart + ": " + numberPart;

						// console.log(`m[${1}]`, m[i]);
						m[i] = m[i].trim();
						m[i] = m[i].match(checkTextInStringRegEx) ? m[i].match(checkTextInStringRegEx)[0].replace(parseIntRegEx, "").trim() : m[i];
						m[i] = m[i].replace(parseIntRegEx, "");
						// console.log(`m[${1}]`, m[i]);
						
						
						newStr += "\t- "+chalk[textColor](m[i] + ": ") +chalk[valueColor].bold(numberPart)+"\n";
						
					}
					newStr += chalk[textColor].bold("---- [END] multiple msg parameters ----");
				}
				msg = newStr;
			}
		}
		return  key + msg;
	}
}

/** 
 * @param {Objet} obj Object
 * Accepted properties:
 * - header - Header to be set outside cycles to print before cycle
 * - footer - Footer to be set outside cycles to print at the end of the cycle
 * - textColor - CLI Output color for strings
 * - valueColor - CLI Output color for values to print
 * - right - Boolean to print right logic of the binary tree
 * - left - Boolean to print left logic of the binary tree
 * - msg - The msg to print
 * - key - The key of the node which is going to be printed
 */
let log = (obj) => console.log(treeLogFormatter(obj));
/*===============================================================================================*/
module.exports = log;