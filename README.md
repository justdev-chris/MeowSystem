# 🐱 MeowSystem

Cat‑themed system library for Lynx.

`prowl`, `sniff`, `hiss`, `scratch`, `claw`, `nap` & more.

---

## 📦 Install

```bash
lynx add meowsys
lynx install
```

---

## 🚀 Usage

```lynx
KittyPort "meowsys"

Set files = prowl(".")
Roar files

Set home = sniff("HOME")
Roar home

hiss("echo Hello from MeowSystem!")
nap(2)
```

---

## 🛠 Functions

| Function | What It Does |
|----------|--------------|
| `prowl(path)` | List files in a directory |
| `sniff(name)` | Get environment variable |
| `hiss(cmd)` | Run a shell command |
| `pad(path)` | Change current directory |
| `scratch(path)` | Create a directory |
| `claw(path)` | Delete a file |
| `bat(old, new)` | Rename or move a file |
| `tail()` | Get current working directory |
| `whisker(path)` | Check if a file or directory exists |
| `nap(seconds)` | Sleep for a given number of seconds |

---

## 🔧 Building the DLL

```bash
cd src
gcc -shared -o ../meowsys.dll meowsys.c -lws2_32
```

Place meowsys.dll in your Lynx lib/ folder.

---

## 📄 License

MIT
