{
"targets":[
{
"target_name": "openfrafsuallylib",
"cflags!": ["-fno-exceptions"],
"cflags_cc!" : ["-fno-exceptions"],
"sources" : [
"src/models/FrameTime.hpp",
"src/models/FrameTimes.hpp",
"src/Calculators/FrameTimeCalculator/FrameTimeCalculator.cpp"
],
"include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
}
]
}