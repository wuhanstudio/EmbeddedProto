Import('RTT_ROOT')
Import('rtconfig')
from building import *

cwd = GetCurrentDir()

src = Glob('src/*.cpp')

if GetDepend('EMBEDDEDPROTO_USING_ENCODE_DECODE_EXAMPLE'):
    src += Glob('examples/encode_decode.cpp')
    src += Glob('examples/UartReadBuffer.cpp')
    src += Glob('examples/UartWriteBuffer.cpp')

CPPPATH = [cwd, ]
CPPPATH += [cwd + '/src']

LOCAL_CPPFLAGS = ''
if rtconfig.CROSS_TOOL == 'gcc':
    LOCAL_CPPFLAGS += ' -std=c++14'

group = DefineGroup('EmbeddedProto', src, depend = ['PKG_USING_EMBEDDEDPROTO'], CPPPATH = CPPPATH, LOCAL_CCFLAGS=LOCAL_CPPFLAGS )

Return('group')






