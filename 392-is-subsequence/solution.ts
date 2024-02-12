export function isSubsequence(s: string, t: string): boolean {
  if (s.length > t.length) {
    return false;
  }

  let sCounter = 0;
  for (const c of t) {
    if (sCounter >= s.length) {
      break;
    }

    if (c === s[sCounter]) {
      ++sCounter;
    }
  }

  return sCounter === s.length;
}
