# CLI ChatGPT in C++

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/c%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![GitHub license](https://img.shields.io/github/license/kjanker/cli-chatgpt-cpp.svg)](https://github.com/kjanker/cli-chatgpt-cpp/blob/main/LICENSE)

A lightweight command-line implementation of ChatGPT in C++.

## Demo

```
~ ./main.out
< How can I help you?
> When did Einstein invent the moon?
< Einstein did not invent the moon. The moon has existed for billions of years.
> Then what did Einstein invent?
< Albert Einstein did not invent anything, but he developed many theories and made significant contributions to the field of physics.
> _
```

## Usage

In order to run the program, you need to set the environment variable ``OPENAI_API_KEY`` with your [Open AI token](https://platform.openai.com/account/api-keys). If you want to customize the request parameters, you can do that with ``config.json``.

## Requirements

❕ [curl](https://curl.se): for web requests  
❕ [boost](https://www.boost.org): for string processing  
☑️ [nlohmann/json](https://github.com/nlohmann/json): for JSON handling (already include)  
☑️ [olrea/openai-cpp](https://github.com/olrea/openai-cpp): for comfortable request hanndling (already include)  

## Open points

🧩 Session history (currently each request is oblivious of past prompts)  
🧩 Commands to start/restart/quit program

## License

[MIT](LICENSE)
