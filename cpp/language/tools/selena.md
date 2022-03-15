https://inside-docupedia.bosch.com/confluence/display/DP/SELENA+Build+System
## 1 解析配置文件
## 2 根据FLUX生成cmake文件
## 3 根据runnable的头文件生成selena的仿真代码
## 4 cmake组成部分(dacore + selena)
set(dc_fw_DIR ${DC_ROOT_DIR}/dc_fw)
set(dc_tools_DIR ${DC_ROOT_DIR}/dc_tools)
set(DADDY_DIR ${MOM_DIR}/daddy)


- components.cmake (ip_dc\dc_fw\components.cmake)
- - set(FLUX_IMPLEMENTATION_COMPONENT_NAME "ad_fw") ad_fw.cmake
- 
```python
# R2D2.py
call_cmake
        cmake_args = [ 'cmake', self.cmake_path,
            '-DRB_PROJECT_TARGET={0}'.format(self.project_target),
            '-DCMAKE_EXPORT_COMPILE_COMMANDS=ON',
            '-DDC_CMAKE_CONFIG=%s' % config_file_path,
            '-DSELENA_SKIP_DINXPARSER=%s' % ('true' if self.skip_dinx_parser else 'false'),
            '-DSELENA_SKIP_NOGEN=%s' % ('true' if self.skip_node_gen else 'false') ]
```
```
(log file)
Calling CMake with arguments '['cmake', 'D:/backup_project/icv_innofund_dasy/ip_dc', '-DRB_PROJECT_TARGET=selena', '-DCMAKE_EXPORT_COMPILE_COMMANDS=ON', '-DDC_CMAKE_CONFIG=D:/backup_project/icv_innofund_dasy/apl_bjev/main/selena/config/cmake/ROSDADDY_PER_SIT_RPM_FCT.config', '-DSELENA_SKIP_DINXPARSER=false', '-DSELENA_SKIP_NOGEN=false', '-DSELENA_USE_MATLAB_TRANSFER=TRUE', '-DSELENA_BUILD_EMULATION_CONTAINER=FALSE', '-DSELENA_GHS_MATH=FALSE', '-DDC_ENABLE_TESTING=ON', '-DDC_ENABLE_COVERAGE=OFF', '-DSELENA_WITH_DEBUG_STATES=TRUE', '-DSELENA_WITH_INTERNAL_STATES=TRUE', '-GVisual Studio 14 2015 Win64', '-Tv140', '-DBOOST_ROOT_DIR=C:\\TCC\\Tools\\boost\\1.63.0_WIN64']'
```
[R2D2 (cmake)] Run `fbg2dcbuild` to generate component cmake files from flux model
[R2D2 (cmake)] Starting generation of the SCOM
[R2D2 (cmake)] Starting generation of PAD parameters
[R2D2 (cmake)] `Adding component`(./cmake/utils/dc_dependencies.cmake:    message("Adding component ")
[R2D2 (cmake)] Running Dinxer
Adding component
[R2D2 (cmake)] Running Dinx parser (dinxxmlparser.py) `selena/config/buildtime/ROSDADDY_PER_SIT_RPM_FCT.xml`
[R2D2 (cmake)] Running NoGen (generateRosDaddyNode.py)

