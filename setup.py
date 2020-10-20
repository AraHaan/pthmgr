from distutils.core import setup, Extension

module1 = Extension('pathmgr',
                    define_macros = [('EDITENV_STATIC', '1')],
                    libraries = ['advapi32', 'user32'], # we depend on window api calls from both of these dlls.
                    include_dirs = ['./externals'],
                    sources = ['pathmgr.cpp', './externals/editenv.cpp', './externals/EnvVar.cpp'])

setup (name = 'pathmgr',
       version = '0.0.1',
       description = '''
Python Bindings to provide what pthmgr provides which allows to modify the Windows
PATH environment variable and automatically tells python about it for you so you
do not need to restart python on Windows.
''',
       author = 'AraHaan',
       author_email = '15173749+AraHaan@users.noreply.github.com',
       url = 'https://github.com/AraHaan/pthmgr',
       long_description = '''
Python Bindings to provide what pthmgr provides which allows to modify the Windows
PATH environment variable and automatically tells python about it for you so you
do not need to restart python on Windows.
''',
       license= 'MIT',
       platforms = ['Windows'],
       ext_modules = [module1])
