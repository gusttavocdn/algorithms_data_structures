/**
 * This function takes an array of booleans called `breaks` and returns the index of the first `true` value in the array.
 * If there are no `true` values in the array, the function returns `-1`.
 * 
 * @param breaks An array of booleans indicating whether a crystal ball is broken or not.
 * @returns The index of the first `true` value in the array or `-1` if there are no `true` values.
 */
export default function two_crystal_balls(breaks: boolean[]): number {
  // Determine the amount to jump between indices when searching for a broken crystal ball.
  const jmpAmount = Math.floor(Math.sqrt(breaks.length));
  // Start searching for a broken crystal ball at the first index to jump to.
  let i = jmpAmount;

  // Search for a broken crystal ball by jumping between indices.
  for (; i < breaks.length; i += jmpAmount) {
    if (breaks[i]) break;
  }

  // If a broken crystal ball was found, move back to the previous jump amount.
  i -= jmpAmount;

  // Search for a broken crystal ball within the previous jump amount.
  for (let j = 0; j < jmpAmount && i < breaks.length; j++, i++) {
    if (breaks[i]) return i;
  }

  // If no broken crystal ball was found, return -1.
  return -1;
}

// two_crystal_balls([false, false, false, false, false, false, false, true, true, true])