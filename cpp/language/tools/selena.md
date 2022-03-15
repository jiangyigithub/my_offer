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
  - COMMAND bash "-c" "python3 -u ${DC_ROOT_DIR}/../cmp_common/tools/fbg2dcbuild/fbg2dcbuild.py ${FBG2DCBUILD_INI_FILE}"
[R2D2 (cmake)] Starting generation of the SCOM 
  - COMMAND bash -c "${APL_DIR}/tools/builder/generate_scom.sh"
[R2D2 (cmake)] Starting generation of PAD parameters 
  - COMMAND bash -c "${APL_DIR}/tools/builder/cmake/GEN_PAD_PARAMS.sh"
[R2D2 (cmake)] `Adding component`(./cmake/utils/dc_dependencies.cmake:    message("Adding component ")
[R2D2 (cmake)] Running Dinxer
Adding component
[R2D2 (cmake)] Running Dinx parser (dinxxmlparser.py) `selena/config/buildtime/ROSDADDY_PER_SIT_RPM_FCT.xml`
[R2D2 (cmake)] Running NoGen (generateRosDaddyNode.py)


## logfile_r2d2

apl_bjev\main\selena\config\cmake\ROSDADDY_PER_SIT_RPM_FCT.config
`message(" ### Paths set in SELENA buildtime config file ####")`

ip_dc\dc_tools\cmake\utils\dc_configure_vbindings.cmake
line 113 -->`message(STATUS "Currently selected vbindings:")`



ip_dc\dc_fw\components.cmake
apl_bjev\component\fal\components.cmake
apl_bjev\components.cmake
line 118 -->`[R2D2 (cmake)] Adding component`

ip_dc\dc_tools\CMakeLists.txt
  - ip_dc\dc_tools\cmake\utils\dc_selena_utils.cmake
  line 216 -->`message("Running Dinx header creator (dinx_header_creator.py) ...")`

set(CORE_CGEN_DIR ${CMAKE_CGEN_DIR}/nogen/ros_nodes/selena/src) 

ip_dc\CMakeLists.txt
`message("CMake build configuration process finished (${END_TIME})")`

## fbg2dcbuild
`dc_add_component(NAME bjev_per_run_spp_rss           DIR ${FAL_DIR}/per/runnables/spp_rss`
(apl_bjev\components.cmake)

`dc_include(${FBG2DCBUILD_SELENA_DIR}/cmake/${FLUX_IMPLEMENTATION_COMPONENT_NAME}.cmake)`
(apl_bjev\component\fal\per\runnables\spp_rss\CMakeLists.txt)


## cmake variable
`FBG2DCBUILD_SELENA_DIR`
set(FBG2DCBUILD_SELENA_DIR "${CMAKE_BINARY_DIR}/../fbg2dcbuild/selena")

`CMAKE_BINARY_DIR`

`CMAKE_CGEN_DIR`
set(CMAKE_CGEN_DIR ${CMAKE_BINARY_DIR}/generated_src)

`CORE_CGEN_DIR`
set(CORE_CGEN_DIR ${CMAKE_CGEN_DIR}/nogen/ros_nodes/selena/src) 

```
./ip_dc/dc_tools/CMakeLists.txt:set(CORE_CGEN_DIR ${CMAKE_CGEN_DIR}/nogen/ros_nodes/selena/src) 
./ip_dc/dc_tools/selena/CMakeLists.txt:set(CORE_CGEN_DIR ${CMAKE_CGEN_DIR}/nogen/ros_nodes/selena/src)
./ip_dc/dc_tools/selena/src/core/CMakeLists.txt:        ${CORE_CGEN_DIR}/core
./ip_dc/dc_tools/selena/src/data_recorder/CMakeLists.txt:        ${CORE_CGEN_DIR}/software_information
./ip_dc/dc_tools/selena/src/data_recorder_plugin_base/CMakeLists.txt:        ${CORE_CGEN_DIR}/software_information
./ip_dc/dc_tools/selena/src/data_recorder_plugin_csv/CMakeLists.txt:        ${CORE_CGEN_DIR}/software_information
./ip_dc/dc_tools/selena/src/data_recorder_plugin_ec/CMakeLists.txt:        ${CORE_CGEN_DIR}/software_information
./ip_dc/dc_tools/selena/src/data_recorder_plugin_mat/CMakeLists.txt:        ${CORE_CGEN_DIR}/software_information
./ip_dc/dc_tools/selena/src/data_recorder_plugin_mdf/CMakeLists.txt:        ${CORE_CGEN_DIR}/software_information
./ip_dc/dc_tools/selena/src/data_recorder_plugin_ros/CMakeLists.txt:        ${CORE_CGEN_DIR}/software_information
./ip_dc/dc_tools/selena/src/main/CMakeLists.txt:        ${CORE_CGEN_DIR}/software_information/
./ip_dc/dc_tools/selena/src/mapping/CMakeLists.txt:    ${CORE_CGEN_DIR}/mapping/selena_mapping_factory.cpp
./ip_dc/dc_tools/selena/src/mapping/CMakeLists.txt:set(MAPPING_CGEN_DIR ${CORE_CGEN_DIR}/core/mapping_plugin)
./ip_dc/dc_tools/selena/src/plugins/static_wrapper_loader/CMakeLists.txt:    #${CORE_CGEN_DIR}/wrapper/selena_wrapper_plugin.cpp
./ip_dc/dc_tools/selena/src/plugins/static_wrapper_loader/CMakeLists.txt:        ${CORE_CGEN_DIR}/core
./ip_dc/dc_tools/selena/src/plugins/wrapper_plugin/CMakeLists.txt:    ${CORE_CGEN_DIR}/wrapper/selena_wrapper_plugin.cpp
./ip_dc/dc_tools/selena/src/plugins/wrapper_plugin/CMakeLists.txt:        ${CORE_CGEN_DIR}/core
./ip_dc/dc_tools/selena/src/wrapper/CMakeLists.txt:    ${CORE_CGEN_DIR}/wrapper/selena_wrapper_factory.cpp
./ip_dc/dc_tools/selena/src/wrapper/CMakeLists.txt:    ${CORE_CGEN_DIR}/core/greybox/*.cpp)
./ip_dc/dc_tools/selena/src/wrapper/CMakeLists.txt:    ${CORE_CGEN_DIR}/core/wrapper/*.cpp)
./ip_dc/dc_tools/selena/src/wrapper/CMakeLists.txt:    ${CORE_CGEN_DIR}/core/doorkeeper/*.cpp)
./ip_dc/dc_tools/selena/src/wrapper/CMakeLists.txt:        ${CORE_CGEN_DIR}/core
./ip_dc/dc_tools/selena.md:set(CORE_CGEN_DIR ${CMAKE_CGEN_DIR}/nogen/ros_nodes/selena/src) 
```