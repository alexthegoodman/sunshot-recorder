# SunShot Recorder

C++ Native Node Module for SunShot (Electron) which allows for the retrieval of window position and size

```
`volta install node@16.16.0`
`npm install`
`npm link` (this way `sunshot` main repo can link back)
```

```
`node-gyp configure`
`node-gyp build`
`node test.js`
```

```
For Electron:
`node-gyp rebuild --target=21.4.4 --platform=win32 --arch=x64 --runtime=electron --abi=109 --uv=1 --libc=glibc --electron=21.4.4 --webpack=true --dist-url=https://electronjs.org/headers`
or
`node-gyp rebuild --target=21.4.4 --arch=x64 --dist-url=https://electronjs.org/headers`
```

Debugging DLLs:
```
C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.36.32532\bin\Hostx64\x64> ./dumpbin /dependents C:\Users\alext\projects\common\sunshot-recorder\build\Release\addon.node
```
