
//extra memcpy should be optimized out
template <class dest, class source>
inline dest bit_cast(const source& s) {
  // Compile time assertion: sizeof(dest) == sizeof(source)
  typedef char assertion[sizeof(dest) == sizeof(source) ? 1 : -1];
  dest d;
  memcpy(&d, &s, sizeof(dest));
  return d;
}
