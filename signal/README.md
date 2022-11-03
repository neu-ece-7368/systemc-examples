# Example for sc_signal

An sc_signal is a combination of data and event. Writing to sc_signal causes an event if the written value is different. The sc_signal distiguishes current and new value. Writing to changes the new value, reading from it returns the current value. Only after time has passed the new value becomes the current value.

```
P pre,  0 s, out: 0, val: 1
C,      0 s, in:  1
P post, 1 ns, out: 1, val: 1
P pre,  1 ns, out: 1, val: 2
C,      1 ns, in:  2
P post, 2 ns, out: 2, val: 2
```

In the procuder *P* the `out` signal does still have the old value pre wait, only post wait the value becomes visible (the wait could wait for actual time or for wait(SC_ZERO_TIME) or waiting for the own event). The consumer *C*, waiting for the event on change sees the new value as `in`.

Additional writes into an sc_signal without passing time will overwrite the previously set value as there is only one new value. 

## References

- [Learn SystemC with Examples](https://learnsystemc.com/basic/signal_bool)
- [SystemC LRM](https://ieeexplore.ieee.org/document/6134619)