#----------------------------------------------------------------------------------
# build_tree-packet: root
#----------------------------------------------------------------------------------
set(root.dep root_install)
set(root_install.dep rf_type7)
set(rf_type7.dep
    rf_type7_rfdsp
    rf_type7_rsip
)

