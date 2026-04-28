- similar to map except that multiple entries CAN have the same key
- dictionaries support these methods:
size() -> return the number of entries in the dictionary
empty() -> return true if dictionary empty
begin() -> return iterator to first entry in the map
end() -> return iterator to the imaginary position right after the last entry in the map
find(k) -> return iterator to the entry with the key k, if no such entry exists return end()
insert(k, v) -> return iterator to the position of the newly created entry
erase(k) -> erase entry with key k, if no such entry exists error
erase(p) -> erase entry at position p, if p points to end() throw error
findAll(k) -> return a pair of iterators (b, e), such that all entries whose key = k  lie in the range [b, e)
* in order to implement findAll(k) we assume that all entries with the same key are stored contiguosly 
