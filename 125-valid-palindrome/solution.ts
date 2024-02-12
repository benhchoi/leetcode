export function isPalindrome(s: string): boolean {
  s = s.toLowerCase();
  s = s.replace(/[\W_]/g, '');
  let i = 0,
    j = s.length - 1;
  while (i < j) {
    if (s[i] !== s[j]) {
      return false;
    }

    ++i;
    --j;
  }

  return true;
}
