# CLI ChatGPT in C++

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/c%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![GitHub license](https://img.shields.io/github/license/kjanker/cli-chatgpt-cpp.svg)](https://github.com/kjanker/cli-chatgpt-cpp/blob/main/LICENSE)

A lightweight command-line implementation of ChatGPT in C++.

## Demo

```
~ ./main.out
< Okay, I'm ready. What can I help you with?
> When did Einstein invent the moon?
< Einstein did not invent the moon. The moon has existed for billions of years.
> So he is just an imposter?
< No, Einstein was a renowned physicist who made significant contributions to the field of science, including the theory of relativity. However, he did not invent the moon.
> _
```

## Usage

In order to run the program, you need to set the environment variable ``OPENAI_API_KEY`` with your [Open AI token](https://platform.openai.com/account/api-keys). If you want to customize the request parameters, you can do that with ``config.json``.

## Requirements

❕ [curl](https://curl.se): for web requests  
☑️ [nlohmann/json](https://github.com/nlohmann/json): for JSON handling (already include)  
☑️ [olrea/openai-cpp](https://github.com/olrea/openai-cpp): for comfortable request hanndling (already include)  

## Open points

🧩 Commands to start/restart/quit program

## License

[MIT](LICENSE)
