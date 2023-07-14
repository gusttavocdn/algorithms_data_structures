/**
 * Sorts an array of numbers using the bubble sort algorithm.
 * @param {number[]} arr - The array of numbers to be sorted.
 * @returns {void}
 */
export default function bubble_sort(arr: number[]): void {
  for (let i = 0; i < arr.length; i += 1) {
    let temp = 0;
    let swapped = false;

    // Loop through the array from the first element to the element
    // before the last element, minus the number of elements that have
    // already been sorted in previous iterations
    for (let j = 0; j < arr.length - i - 1; j += 1) {
      // If the current element is greater than the next element
      if (arr[j] > arr[j + 1]) {
        // Swap the current element with the next element
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }

    // If no swaps occurred in this iteration, the array is sorted
    if (swapped === false) return;
  }
  return;
}
