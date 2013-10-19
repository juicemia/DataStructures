#ifndef _DICT_ENTRY_H_
#define _DICT_ENTRY_H_

template <typename K, typename E>
class DictEntry {
    K key;
    E entry;

    public:
        DictEntry(K, E);
};

template <typename K, typename E>
DictEntry<K, E>::DictEntry(K key_param, E entry_param)
{
    key = key_param;
    entry = entry_param;
}
#endif //_DICT_ENTRY_H_
