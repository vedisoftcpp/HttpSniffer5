#ifndef TIMING_MAP_H
#define TIMING_MAP_H

#include <map>
#include <time.h>



//template <typename KeyT, typename ValueT>
//class timing_map
//{
//private:
//    struct timing_value
//    {
//        time_t last_using_time;
//        ValueT value;
//    };

//public:
//    timing_map(time_t rescan_time, time_t lifetime) :
//        _rescan_time(rescan_time),
//        _lifetime(lifetime),
//        _last_scan_time(::time(0)),
//        _tm()
//    {

//    }

//    ValueT& operator[] (const KeyT& key)
//    {
//        update_timing(key);
//        scan();
//        check_value(key);
//        return _tm[key].value;
//    }

//private:
//    time_t _rescan_time;
//    time_t _lifetime;
//    time_t _last_scan_time;
//    std::map<KeyT, timing_value> _tm;

//    void scan()
//    {
//        time_t now = ::time(0);
//        if (now - _last_rescan_time > _rescan_time)
//        {
//            for (std::map<KeyT, timing_value>::iterator it = _tm.begin(); it != _tm.end(); )
//            {
//                timing_value& tv = it->second;
//                if (now - tv.last_using_time < _lifetime)
//                {
//                    _tm.erase(it++);
//                }
//                else
//                {
//                    ++it;
//                }
//            }
//            _last_rescan_time = now;
//        }
//    }

//    void check_value(const KeyT& key)
//    {
//        std::map<KeyT, timing_value>::iterator it = _tm.find(key);
//        if (it == _tm.end())
//        {
//            throw 1;
//        }
//    }

//    void update_timing(const KeyT& key)
//    {
//        check_value(key);
//        _tm[key].last_using_time = ::time(0);
//    }
//};


#endif // TIMING_MAP_H
