class MyCalendar {
    map<int, int> events;   // <endTime, statIme>
public:  
  
  bool book(int start, int end) {
        auto next = events.upper_bound(start);
        if(next != events.end() &&   (*next).second < end)return false;
        events.insert({end,start});
        return true;
    }
};