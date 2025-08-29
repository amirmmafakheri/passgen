# PassGen 🔑

A simple command-line password generator written in C.  
It generates secure random passwords containing:

- Lowercase letters `a-z`
- Uppercase letters `A-Z`
- Digits `0-9`
- Special characters `!@#$%^&*`

---

## Usage

### Build
On Linux / macOS:
```bash
gcc passgen.c -o passgen
```

On Windows (MinGW):
```bash
gcc passgen.c -o passgen.exe
```

### Run
```bash
./passgen <length>
```

Example:
```bash
./passgen 35
```

Output:
```
Aj9&bM8#xY$2kP7@wQ!eS0hR
```

---

## Notes
- Default RNG uses `rand()` seeded with `time(NULL)`.  
- For production-grade security, consider replacing `rand()` with a cryptographically secure RNG (e.g., `/dev/urandom` on Linux or `BCryptGenRandom` on Windows).  
- This project is kept simple for educational purposes.

---

## License
MIT License
