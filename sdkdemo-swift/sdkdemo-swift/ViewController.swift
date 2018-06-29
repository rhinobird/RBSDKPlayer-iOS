//
//  ViewController.swift
//  sdkdemo-swift
//
//  Created by Benjamin Fantini on 5/15/18.
//  Copyright © 2018 Rhinobird Inc. All rights reserved.
//

import UIKit

import RBSDKPlayer

class ViewController: UIViewController {

    @IBOutlet weak var playerContainerView: UIView?
    var playerController: RBSDKPlayerViewController?

    override func viewDidLoad() {
        super.viewDidLoad()

        RBSDK.sharedInstance().loadAsynchronously { success, error in
            if (success) {
                DispatchQueue.main.async {
                    self.loadPlayer()
                }

            } else if let error = error {
                print("Error trying to configure the sdk: \(error)")
            }
        }
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()

        if let bounds = playerContainerView?.bounds {
            playerController?.view.frame = bounds
        }
    }

    func loadPlayer() {
        self.playerController = RBSDKPlayerViewController(momentId: "comeymemos-f19599",
                                                          autoplay: true)
        self.playerController?.setDelegate(self)

        if let playerController = self.playerController,
            let playerContainerView = self.playerContainerView {
            playerController.view.frame = playerContainerView.bounds
            playerController.view.autoresizingMask = [.flexibleWidth,
                                                      .flexibleHeight]
            playerContainerView.addSubview(playerController.view)
            self.addChildViewController(playerController)
        }
    }
}

// MARK: RBPlayerViewControllerDelegate

extension ViewController: RBPlayerViewControllerDelegate {

    func playerControllerLoadDidSucceed(_ succeed: Bool) {
        if (succeed) {
            print("Player load succeed")
        } else {
            print("Player was not able to load")
        }
    }
}

