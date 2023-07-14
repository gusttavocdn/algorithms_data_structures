export default function bs_list(haystack: number[], needle: number): boolean {
  let low_position = 0;
  let high_position = haystack.length;

  while (low_position < high_position) {
    const middle = Math.floor(low_position + (high_position - low_position) / 2);
    const value = haystack[middle];

    if (value == needle) return true;

    if (value > needle)
      high_position = middle;
    else
      low_position = middle + 1;
  }

  return false;
}
