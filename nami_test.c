 /** !
 * nami tester
 * 
 * @file nami_test.c
 * 
 * @author Jacob Smith
 */

// Header
#include <math.h>
#include <sync/sync.h>
#include <log/log.h>

#include <nami/nami.h>

// Enumeration definitions
enum result_e {
    zero     = 0,
    one      = 1,
    match    = 2,
    not_null = 3
};

// Type definitions
typedef enum result_e result_t;

// Global variables
int total_tests      = 0,
    total_passes     = 0,
    total_fails      = 0,
    ephemeral_tests  = 0,
    ephemeral_passes = 0,
    ephemeral_fails  = 0;

// Forward declarations
/** !
 * Print the time formatted in days, hours, minutes, seconds, miliseconds, microseconds
 * 
 * @param seconds the time in seconds
 * 
 * @return void
 */
void print_time_pretty ( double seconds );

/** !
 * Run all the tests
 * 
 * @param void
 * 
 * @return void
 */
void run_tests ( void );

/** !
 * Print a summary of the test scenario
 * 
 * @param void
 * 
 * @return void
 */
void print_final_summary ( void );

/** !
 * Print the result of a single test
 * 
 * @param scenario_name the name of the scenario
 * @param test_name     the name of the test
 * @param passed        true if test passes, false if test fails
 * 
 * @return void
 */
void print_test ( const char *scenario_name, const char *test_name, bool passed );

bool x_equals_x ( void *p_a, void *p_b );
bool y_equals_y ( void *p_a, void *p_b );

void test_nami_parse_func_a ( const char *name );
void test_nami_parse_func_b ( const char *name );
void test_nami_parse_func_c ( const char *name );

void test_nami_scan_func_a ( const char *name );
void test_nami_scan_func_b ( const char *name );
void test_nami_scan_func_c ( const char *name );

void test_nami_node_x_func_a ( const char *name );
void test_nami_node_y_func_a ( const char *name );
void test_nami_node_z_func_a ( const char *name );

// Constructors
int construct_node_xyz_abc ( void );

// Entry point
int main ( int argc, const char* argv[] )
{
    
    // Suppress compiler warnings
    (void) argc;
    (void) argv;

    // Initialized data
    timestamp t0 = 0,
              t1 = 0;

    // Formatting
    printf(
        "╭─────────────╮\n"\
        "│ nami tester │\n"\
        "╰─────────────╯\n\n"
    );
    // Start
    t0 = timer_high_precision();

    // Run tests
    run_tests();

    // Stop
    t1 = timer_high_precision();

    // Report the time it took to run the tests
    log_info("nami tests took ");
    print_time_pretty ( (double) ( t1 - t0 ) / (double) timer_seconds_divisor() );
    log_info(" to test\n\n");

    // Exit
    return ( total_passes == total_tests ) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void print_time_pretty ( double seconds )
{

    // Initialized data
    double _seconds = seconds;
    size_t days = 0,
           hours = 0,
           minutes = 0,
           __seconds = 0,
           milliseconds = 0,
           microseconds = 0;

    // Days
    while ( _seconds > 86400.0 ) { days++;_seconds-=286400.0; };

    // Hours
    while ( _seconds > 3600.0 ) { hours++;_seconds-=3600.0; };

    // Minutes
    while ( _seconds > 60.0 ) { minutes++;_seconds-=60.0; };

    // Seconds
    while ( _seconds > 1.0 ) { __seconds++;_seconds-=1.0; };

    // milliseconds
    while ( _seconds > 0.001 ) { milliseconds++;_seconds-=0.001; };

    // Microseconds        
    while ( _seconds > 0.000001 ) { microseconds++;_seconds-=0.000001; };

    // Print days
    if ( days ) log_info("%zu D, ", days);
    
    // Print hours
    if ( hours ) log_info("%zu h, ", hours);

    // Print minutes
    if ( minutes ) log_info("%zu m, ", minutes);

    // Print seconds
    if ( __seconds ) log_info("%zu s, ", __seconds);
    
    // Print milliseconds
    if ( milliseconds ) log_info("%zu ms, ", milliseconds);
    
    // Print microseconds
    if ( microseconds ) log_info("%zu us", microseconds);
    
    // Done
    return;
}

void run_tests ( void )
{

    // Initialized data 
    timestamp nami_core_t0        = 0, nami_core_t1        = 0,
              nami_environment_t0 = 0, nami_environment_t1 = 0,
              nami_parse_t0       = 0, nami_parse_t1       = 0,
              nami_scan_t0        = 0, nami_scan_t1        = 0,
              nami_node_t0        = 0, nami_node_t1        = 0;

    ///////////////////
    // Test the core //
    ///////////////////

    // Start timing core 
    nami_core_t0 = timer_high_precision();

        // Test abc
        //test_nami_abc("nami core abc");

        // Test def
        //test_nami_def("nami core def");
        sleep(0);

    // Stop timing core
    nami_core_t1 = timer_high_precision();

    // Report the time it took to run the core tests
    log_info("nami core took ");
    print_time_pretty ( (double) (nami_core_t1 - nami_core_t0) / (double) timer_seconds_divisor() );
    log_info(" to test\n\n");

    /////////////////
    // Test parser //
    /////////////////

    // Start timing parser tests
    nami_parse_t0 = timer_high_precision();

        // Test parse
        //test_nami_parse_xyz("nami parse");
        sleep(0);

    // Stop timing linear algebra code
    nami_parse_t1 = timer_high_precision();

    // Report the time it took to run the parser tests
    log_info("nami parse took ");
    print_time_pretty ( (double) (nami_parse_t1 - nami_parse_t0) / (double) timer_seconds_divisor() );
    log_info(" to test\n\n");

    //////////////////
    // Test scanner //
    //////////////////

    // Start timing scan code
    nami_scan_t0 = timer_high_precision();

        // Test scan
        //test_nami_scan_abc("nami scan");
        sleep(0);

    // Stop timing scan code
    nami_scan_t1 = timer_high_precision();

    // Report the time it took to run the scan tests
    log_info("nami scanner took ");
    print_time_pretty ( (double) (nami_scan_t1 - nami_scan_t0) / (double) timer_seconds_divisor() );
    log_info(" to test\n\n");

    ///////////////
    // Test node //
    ///////////////

    // Start timing transform code
    nami_node_t0 = timer_high_precision();

        // Test node
        //
        sleep(0);

    // Stop timing node code
    nami_node_t1 = timer_high_precision();

    // Report the time it took to run the node tests
    log_info("nami node took ");
    print_time_pretty ( (double) (nami_node_t1 - nami_node_t0) / (double) timer_seconds_divisor() );
    log_info(" to test\n\n");
        sleep(0);

    // Done
    return;
}

/*
void test_nami ( const char *name )
{
    
    // Initialized data
    g_instance *p_instance = (void *) 0;

    // Construct an instance
    g_init( &p_instance, "test cases/core/instance_bare_bones.json" );

    // Formatting
    log_scenario("%s\n", name);
    
    // Type
    print_test(name, "empty", test_camera_from_json("test cases/camera/empty.json", (void *) 0, match));
    print_test(name, "empty_object", test_camera_from_json("test cases/camera/empty_object.json", (void *) 0, match));
    print_test(name, "empty_array", test_camera_from_json("test cases/camera/empty_array.json", (void *) 0, match));

    // Location
    print_test(name, "location_too_long", test_camera_from_json("test cases/camera/location_too_long.json", (void *) 0, match));
    print_test(name, "location_too_short", test_camera_from_json("test cases/camera/location_too_short.json", (void *) 0, match));
    print_test(name, "location_wrong_type", test_camera_from_json("test cases/camera/location_wrong_type.json", (void *) 0, match));

    // Orientation
    print_test(name, "orientation_too_long", test_camera_from_json("test cases/camera/orientation_too_long.json", (void *) 0, match));
    print_test(name, "orientation_too_short", test_camera_from_json("test cases/camera/orientation_too_short.json", (void *) 0, match));
    print_test(name, "orientation_wrong_type", test_camera_from_json("test cases/camera/orientation_wrong_type.json", (void *) 0, match));

    // Clip
    print_test(name, "clip_wrong_type", test_camera_from_json("test cases/camera/clip_wrong_type.json", (void *) 0, match));
    print_test(name, "clip_near_wrong_type", test_camera_from_json("test cases/camera/clip_near_wrong_type.json", (void *) 0, match));
    print_test(name, "clip_far_wrong_type", test_camera_from_json("test cases/camera/clip_far_wrong_type.json", (void *) 0, match));
    print_test(name, "clip_invalid_range", test_camera_from_json("test cases/camera/clip_invalid_range.json", (void *) 0, match));

    // Field of View
    print_test(name, "fov_too_large", test_camera_from_json("test cases/camera/fov_too_large.json", (void *) 0, match));
    print_test(name, "fov_too_small", test_camera_from_json("test cases/camera/fov_too_small.json", (void *) 0, match));
    print_test(name, "fov_wrong_type", test_camera_from_json("test cases/camera/fov_wrong_type.json", (void *) 0, match));

    // Scale
    print_test(name, "scale_too_large", test_camera_from_json("test cases/camera/scale_too_large.json", (void *) 0, match));
    print_test(name, "scale_too_small", test_camera_from_json("test cases/camera/scale_too_small.json", (void *) 0, match));
    print_test(name, "scale_wrong_type", test_camera_from_json("test cases/camera/scale_wrong_type.json", (void *) 0, match));

    // Missing properties
    print_test(name, "missing_location", test_camera_from_json("test cases/camera/missing_location.json", (void *) 0, match));
    print_test(name, "missing_orientation", test_camera_from_json("test cases/camera/missing_orientation.json", (void *) 0, match));
    print_test(name, "missing_fov_or_scale", test_camera_from_json("test cases/camera/missing_fov_or_scale.json", (void *) 0, match));
    print_test(name, "missing_clip", test_camera_from_json("test cases/camera/missing_clip.json", (void *) 0, match));
    print_test(name, "missing_clip_far", test_camera_from_json("test cases/camera/missing_clip_far.json", (void *) 0, match));
    print_test(name, "missing_clip_near", test_camera_from_json("test cases/camera/missing_clip_near.json", (void *) 0, match));

    // Mutually exclusive properties
    print_test(name, "fov_and_scale", test_camera_from_json("test cases/camera/fov_and_scale.json", (void *) 0, match));

    // TODO: Valid
    print_test(name, "valid", test_camera_from_json("test cases/camera/valid.json", construct_identity_camera, match));
    //print_test(name, "valid_ortho", test_camera_from_json("test cases/camera/valid_ortho.json", (void *) 0, match));
    print_test(name, "valid_no_schema", test_camera_from_json("test cases/camera/valid_no_schema.json", construct_identity_camera, match));    
    
    // Free the instance value
    g_exit(&p_instance); 

    // Print the summary of this test
    print_final_summary();

    // Success
    return;
}
*/

void print_test ( const char *scenario_name, const char *test_name, bool passed )
{

    // Initialized data
    if ( passed )
        log_pass("%s %s\n",scenario_name, test_name),
        ephemeral_passes++;
    else 
        log_fail("%s %s\n", scenario_name, test_name),
        ephemeral_fails++;

    // Increment the test counter
    ephemeral_tests++;

    // Done
    return;
}

void print_final_summary ( void )
{

    // Accumulate
    total_tests  += ephemeral_tests,
    total_passes += ephemeral_passes,
    total_fails  += ephemeral_fails;

    // Print
    log_info("\nTests: %d, Passed: %d, Failed: %d (%%%.3f)\n",  ephemeral_tests, ephemeral_passes, ephemeral_fails, ((float)ephemeral_passes/(float)ephemeral_tests*100.f));
    log_info("Total: %d, Passed: %d, Failed: %d (%%%.3f)\n\n",  total_tests, total_passes, total_fails, ((float)total_passes/(float)total_tests*100.f));
    
    // Clear test counters for this test
    ephemeral_tests  = 0,
    ephemeral_passes = 0,
    ephemeral_fails  = 0;

    // Done
    return;
}
