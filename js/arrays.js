const log = require("./logger");

function isMinHeap(arr){
	let isHeap = true;
	
	for (let i = 0; i < arr.length; i++){
		let left = 2 * i;
		let right = 2 * i + 1;
		let curr = i;

		if (left <= arr.length && arr[curr] > arr[left]){
			isHeap = false;
		} 
		if (right <= arr.length && arr[curr] > arr[right]) {
			isHeap = false;
		}
	}
	return isHeap;
}

/** ======================================================================================================== */
/** ======================================= ACME ROUTINE START ============================================= */
/** ======================================================================================================== */

function ACMECheck(arr){
	let countOverZero = 0;
	let maxDays = 0;
	for (let i = 0; i<arr.length; i++){
		if (arr[i] > 0) {
			countOverZero++;
		}
		if (arr[i] < 0){
			if (countOverZero > maxDays) {
				maxDays = countOverZero;
				countOverZero = 0;
			}
		}
	}
	return maxDays;
}

function ACMECrescendum(arr){
	let count = 1;
	let maxDays = 0;

	for (let i = 1; i < arr.length; i++){
		if (arr[i] > arr[i-1]){
			count++;
		}
		if (count > maxDays) maxDays = count;
		if(arr[i] < arr[i-1]){
			count = 1;
		}
	}
	return maxDays;
}

function oracleFromArray(arr, k){
	let newArr = [];
	for (let i = 0; i <= k; i++){
		newArr[i] = 0;
		for(let j = 0; j < arr.length; j++){
			if (arr[j] === i){
				newArr[i] = newArr[i] + 1;
			}
		}
	}
	return newArr;
}

function ACMERoutine(){
	const maxK = 12;
	let ACMEarr = [0.1,-0.8,0.2,0.3,1.2,-0.9,0.0,-1.7,-2];
	let ACMECrescendumArr = [maxK,3,5,7,8,4,6,6];
	let ACMEdays = ACMECheck(ACMEarr);
	let ACMECrescendumDays = ACMECrescendum(ACMECrescendumArr);
	let oracleArray = oracleFromArray(ACMECrescendumArr, maxK);
	log({msg:"ACME Array days count: "+ACMEdays+"ACME Crescendum Days: "+ACMECrescendumDays+"oracleArray: "+oracleArray, textColor: "magenta"});
}
/** ======================================================================================================== */
/** ======================================== ACME ROUTINE END ============================================== */
/** ======================================================================================================== */

function esisteSomma(arr, num){
	let values = [];
	for (let i = 0; i < num - 1; i++){
		values[i] = false;
	}

	for(let i = 0; i < arr.length; i++){
		if (arr[i] < num){
			values[arr[i]] = true;

		}
	}
	for (let i = 0; i < Math.floor(num/2); i++){
		if (values[i] && values[num - i]){
			return  {val1: i, val2: num-i, exists: true};
		}
	}
	return {exists: false};
}

function fondiDueArray(arr1, arr2){
	let i = 0;
	let j = 0;
	let k = 0;
	let final = [];

	while(i < arr1.length && j < arr2.length){
		if (arr1[i] > arr2[j]){
			final[k] = arr2[j];

			j++;
		} else {
			final[k] = arr1[i];

			i++;
		}
		k++;
	}
	while (i < arr1.length){
		final[k] = arr1[i];
		i++;
		k++;
	}
	while(j < arr2.length){
		final[k] = arr2[j];
		j++;
		k++;
	}
	log({msg: "Ordered merged array: "+final, textColor: "magenta"});
	return final;
}

function stringPalindromaInArray(arr, left, right){
	if (arr[left] === arr[right] && left < right){
		return true && stringPalindromaInArray(arr, left + 1, right -1);
	}
	if (left > right) return true;
	return false;
}

function ordinaSubArrayCrescenteSubArrayDecrescente(arr, i){
	let OUT = [];
	let left = 0;
	let right = arr.length -1;
	let pivot = 0;
		
	while (left <= i && right >= i){
		if(arr[left] < arr[right]){
			OUT[pivot] = arr[left];
			left++;
		} else {
			OUT[pivot] = arr[right];
			right--;
		}
		pivot++;
	}

	while (left <= i){
		OUT[pivot] = arr[left];
		left++;
		pivot++;
	}

	while (right >= i){
		OUT[pivot] = arr[right];
		right--;
		pivot++;
	}
	return OUT;
}

function trovaValoreMancante(arr, left, right){
	if (left > right) return left;
	if (arr[left] + 1 === arr[left + 1]){
		return trovaValoreMancante(arr,left+1,right);
	} else if (arr[right] - 1 === arr[right - 1]){
		return trovaValoreMancante(arr,left,right-1);
	} else {
		return left + 1;
	}
}

function orderZeroOneArray(arr){
	let i = 0;
	let j = arr.length - 1;

	while (i < j ){

		if (arr[i] === 0){
			i++;
		} else {
			if (arr[j] === 1){
				j--;
			}
		}
		let t = arr[j];
		arr[j] = arr[i];
		arr[i] = t;
	}
	return arr;
}

function arrayIntersection(arr1, arr2){
	let left1 = 0;
	let left2 = 0;
	let right1 = arr1.length - 1;
	let right2 = arr2.length - 1;

	let intersectionArr = [];
	while (left1 <= right1 && left2 <= right2){
		if (arr1[left1] < arr2[left2]){
			intersectionArr.push(arr1[left1]);
			left1++;
		} else if (arr1[left1] > arr2[left2]){
			left2++;
		} else {
			left1++;
			left2++;
		}
	}

	while(left1 <= right1){
		intersectionArr.push(arr1[left1]);
		left1++;
	}

	return intersectionArr;
}

function findMissingTwo(arr){
	let B = [];
	for (let i = 0; i < arr.length; i++){
		B[arr[i]] = false;
	}

	for (let i = 0; i < arr.length; i++){
		B[arr[i]] = true;
	}

	let returnArr = [];
	for (let j = 0; j < B.length; j++){
		if (!B[j]) returnArr.push(j);
	}
	return returnArr;
}

function moveLeftNegativeValues(arr){
	let left = 0;
	let right = arr.length - 1;
	while (left < right){
		if (arr[left] < 0){
			left++;
		} else {
				if (arr[right] > 0){
				right--;
			}
		}
		let t = arr[left];
		arr[left] = arr[right];
		arr[right] = t;
	}
	return arr;
}
function swap(arr, val1, val2){
	let tmp = arr[val1];
	arr[val1] = arr[val2];
	arr[val2] = tmp;
}
function flagAlgorithm(arr){
	let left = 0;
	let mid = 0;
	let right = arr.length -1;

	while (left <= right){
		if (arr[left] === "B"){
			left++;
		} else if (arr[left] === "V"){
			swap(arr, left, mid);
			left++;
			mid++;
		} else {
			swap(arr, left, right);
			right--;
		}

	}

	return arr;
}

function mergeSortInQuattroParti(arr, left, right){
	if (left >= right){
		return;
	} else {
		let m = Math.floor((right + left) / 2);
		let m_left = Math.floor((m + left) / 2);
		let m_right = Math.floor((m + right) / 2);
		mergeSortInQuattroParti(arr,left,m_left);
		mergeSortInQuattroParti(arr,m_left+1,m);
		mergeSortInQuattroParti(arr,m+1,m_right);
		mergeSortInQuattroParti(arr,m_right+1,right);
		mergeInQuattro(arr, left, m_left, m);
		mergeInQuattro(arr, m_left, m, m_right);
		mergeInQuattro(arr, left, m, right);
	}
}

function mergeInQuattro(arr, left, mid, right){
	let i1 = mid - left + 1;
	let i2 = right - mid;
	
	let LEFT = [];
	let RIGHT = [];

	for (let i = 0; i < i1; i++){
		LEFT[i] = arr[i + left];
	}
	for (let j = 0; j < i2; j++){
		RIGHT[j] = arr[mid + j + 1];
	}

	let i,j,k = 0;
	while(i <= left && j <= right){
		if (LEFT[i] < RIGHT[j]){
			arr[k] = LEFT[i];
			i=i+1;
		} else {
			arr[k] = RIGHT[j];
			j=j+1;
		}
		k = k+1;
	}
	while(i <= left){
		arr[k] = LEFT[i];
		i=i+1;
		k=k+1;
	}
	while(j <= right){
		arr[k] = RIGHT[j];
		k=k+1;
		j=j+1;
	}
}

function main(){

	let minHeapArr = [3,4,5,6,7,8,10];
	let secondoArray = [1,2,9,11,12,13];

	let palindromeArray = ["A","B","A","N","A","B","A","C"];

	let isHeap = isMinHeap(minHeapArr) ? 1 : 0;

	let esisteSommaUgualeA_17 = esisteSomma(minHeapArr, 16).exists ? 1 : 0;

	let n = fondiDueArray(minHeapArr, secondoArray);
	let p = stringPalindromaInArray(palindromeArray,0,palindromeArray.length-1 ) ? 1 : 0;

	let ascDescArray = [1,7,8,9,11,13,10,8,7,5];
	let ordinaAscDescArray = ordinaSubArrayCrescenteSubArrayDecrescente(ascDescArray, ascDescArray.length/2);

	let mancanteArray = [0,1,2,3,4,5,6,7,8,9,10,11,12];
	let trovaValore = trovaValoreMancante(mancanteArray,0,mancanteArray.length);

	let zeroUnoArray = [1,1,1,1,1,1,1,1,0,1];
	let ordineZeroUno = orderZeroOneArray(zeroUnoArray);

	let arrA = [1,4,6,7,8,19,23];
	let arrB = [2,3,5,7,8,9,10,11];
	let intersection = arrayIntersection(arrA, arrB);

	let arrWithTwoMiss = [0,1,2,3,5,6,7,8,9,10,12];
	let iDueMancanti = findMissingTwo(arrWithTwoMiss);

	let negativeArray = [-2,10,2,3,-4,-1,7,-10];
	let orderedNegArray = moveLeftNegativeValues(negativeArray);

	//ordine: verde bianco rosso
	let flagArray = ["B","R","V","R","R","R","V","B","B","V"];
	let flagResult = flagAlgorithm(flagArray).toString();

	let mergedIn4 = mergeSortInQuattroParti(ascDescArray, 0, ascDescArray.length);
	log({msg: 
	"isMinHeap: "+isHeap+
	"Esiste somma uguale a 17: "+esisteSommaUgualeA_17+
	"Is palindrome: "+p+
	"Ordine array AscDesc\n:"+ ordinaAscDescArray+
	"Valore mancante: "+trovaValore+
	"Ordine zeroUno: "+ordineZeroUno+
	"Interscetion array: "+intersection+
	"I due mancanti: "+iDueMancanti+
	"Ordered negative array: "+orderedNegArray+
	"Flag result: "+flagResult, textColor: "magenta"});
}

module.exports = main();